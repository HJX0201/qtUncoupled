function(generate_benchmark_sources variant action_count output_variable)
    set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated/${variant}")
    file(MAKE_DIRECTORY "${generated_dir}")

    set(business_header "${generated_dir}/business_context.h")
    set(ui_header "${generated_dir}/ui_context.h")
    set(main_source "${generated_dir}/main.cpp")

    file(WRITE "${business_header}" [=[
#pragma once

class BusinessContext final
{
public:
    int run(int actionIndex, int uiBias, bool checked) const noexcept
    {
        const int checkedContribution = checked ? 97 : 0;
        return (((((actionIndex + 1) * 17) ^ (uiBias + actionIndex * 3))
                 + checkedContribution) % 1000003);
    }
};
]=])

    file(WRITE "${ui_header}" [=[
#pragma once

class UiContext final
{
public:
    int bias() const noexcept { return 29; }
};
]=])

    math(EXPR last_index "${action_count} - 1")
    set(expected_checksum 0)
    foreach(index RANGE 0 ${last_index})
        math(EXPR value "(((((${index} + 1) * 17) ^ (29 + ${index} * 3)) + 97) % 1000003)")
        math(EXPR expected_checksum "${expected_checksum} + ${value}")
    endforeach()

    set(generated_sources "${business_header}" "${ui_header}")

    if(variant STREQUAL "direct_binding")
        set(main_includes "")
        set(main_body "")

        foreach(index RANGE 0 ${last_index})
            set(header "${generated_dir}/direct_function_${index}.h")
            set(source "${generated_dir}/direct_function_${index}.cpp")

            file(WRITE "${header}" "#pragma once\n\n#include <QObject>\n\n#include \"business_context.h\"\n\nclass DirectFunction${index} final : public QObject\n{\n    Q_OBJECT\n\npublic:\n    DirectFunction${index}(BusinessContext& business, int uiBias, QObject* parent = nullptr);\n    int result() const noexcept { return result_; }\n    int executionCount() const noexcept { return executionCount_; }\n\npublic slots:\n    void execute(bool checked);\n\nprivate:\n    BusinessContext& business_;\n    int uiBias_;\n    int result_ = 0;\n    int executionCount_ = 0;\n};\n")

            file(WRITE "${source}" "#include \"direct_function_${index}.h\"\n\nDirectFunction${index}::DirectFunction${index}(BusinessContext& business, int uiBias, QObject* parent)\n    : QObject(parent), business_(business), uiBias_(uiBias)\n{\n}\n\nvoid DirectFunction${index}::execute(bool checked)\n{\n    result_ = business_.run(${index}, uiBias_, checked);\n    ++executionCount_;\n}\n")

            string(APPEND main_includes "#include \"direct_function_${index}.h\"\n")
            string(APPEND main_body "    DirectFunction${index} function${index}(business, ui.bias());\n    QAction action${index};\n    action${index}.setCheckable(true);\n    QObject::connect(&action${index}, &QAction::triggered, &function${index}, &DirectFunction${index}::execute);\n    action${index}.trigger();\n    checksum += function${index}.result();\n    executionCount += function${index}.executionCount();\n")
            list(APPEND generated_sources "${header}" "${source}")
        endforeach()

        file(WRITE "${main_source}" "#include <QAction>\n#include <QApplication>\n\n#include <iostream>\n\n#include \"ui_context.h\"\n${main_includes}\nint main(int argc, char** argv)\n{\n    QApplication application(argc, argv);\n    BusinessContext business;\n    UiContext ui;\n    long long checksum = 0;\n    int executionCount = 0;\n${main_body}\n    constexpr long long expected = ${expected_checksum};\n    std::cout << \"variant=\" << BENCH_VARIANT_NAME\n              << \" count=${action_count} executions=\" << executionCount\n              << \" checksum=\" << checksum << '\\n';\n    return checksum == expected && executionCount == ${action_count} ? 0 : 2;\n}\n")
    elseif(variant STREQUAL "string_registry")
        set(invocation_header "${generated_dir}/function_invocation.h")
        set(interface_header "${generated_dir}/ifunction.h")
        set(registry_header "${generated_dir}/function_registry.h")
        set(registry_source "${generated_dir}/function_registry.cpp")
        set(router_header "${generated_dir}/action_router.h")
        set(router_source "${generated_dir}/action_router.cpp")
        set(factories_header "${generated_dir}/function_factories.h")
        set(register_header "${generated_dir}/register_all_functions.h")
        set(register_source "${generated_dir}/register_all_functions.cpp")

        file(WRITE "${invocation_header}" [=[
#pragma once

struct FunctionInvocation final
{
    int uiBias = 0;
    bool checked = false;
};
]=])

        file(WRITE "${interface_header}" [=[
#pragma once

#include "function_invocation.h"

class IFunction
{
public:
    virtual ~IFunction() = default;
    virtual int execute(const FunctionInvocation& invocation) = 0;
};
]=])

        file(WRITE "${registry_header}" [=[
#pragma once

#include <cstddef>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>

#include "ifunction.h"

class FunctionRegistry final
{
public:
    bool registerFunction(std::string id, std::unique_ptr<IFunction> function);
    std::optional<int> execute(
        const std::string& id,
        const FunctionInvocation& invocation) const;
    std::size_t size() const noexcept { return functions_.size(); }

private:
    std::unordered_map<std::string, std::unique_ptr<IFunction>> functions_;
};
]=])

        file(WRITE "${registry_source}" [=[
#include "function_registry.h"

#include <utility>

bool FunctionRegistry::registerFunction(
    std::string id,
    std::unique_ptr<IFunction> function)
{
    if (id.empty() || !function || functions_.find(id) != functions_.end())
        return false;

    functions_.emplace(std::move(id), std::move(function));
    return true;
}

std::optional<int> FunctionRegistry::execute(
    const std::string& id,
    const FunctionInvocation& invocation) const
{
    const auto found = functions_.find(id);
    if (found == functions_.end())
        return std::nullopt;

    return found->second->execute(invocation);
}
]=])

        file(WRITE "${router_header}" [=[
#pragma once

#include <cstddef>
#include <string>

class QAction;
class FunctionRegistry;
class UiContext;

struct RouterState final
{
    long long checksum = 0;
    std::size_t dispatchCount = 0;
    std::size_t failedDispatchCount = 0;
    std::string lastFunctionId;
};

class ActionRouter final
{
public:
    ActionRouter(
        FunctionRegistry& registry,
        const UiContext& ui,
        RouterState& state) noexcept;

    void dispatch(QAction* action);

private:
    FunctionRegistry& registry_;
    const UiContext& ui_;
    RouterState& state_;
};
]=])

        file(WRITE "${router_source}" [=[
#include "action_router.h"

#include <QAction>
#include <QString>

#include "function_registry.h"
#include "ui_context.h"

ActionRouter::ActionRouter(
    FunctionRegistry& registry,
    const UiContext& ui,
    RouterState& state) noexcept
    : registry_(registry), ui_(ui), state_(state)
{
}

void ActionRouter::dispatch(QAction* action)
{
    if (!action) {
        ++state_.failedDispatchCount;
        return;
    }

    state_.lastFunctionId = action->data().toString().toStdString();
    const FunctionInvocation invocation{ui_.bias(), action->isChecked()};
    const auto result = registry_.execute(state_.lastFunctionId, invocation);
    if (!result) {
        ++state_.failedDispatchCount;
        return;
    }

    state_.checksum += *result;
    ++state_.dispatchCount;
}
]=])

        set(factory_declarations "#pragma once\n\n#include <memory>\n\nclass BusinessContext;\nclass IFunction;\n\n")
        set(register_entries "")
        set(main_actions "")

        foreach(index RANGE 0 ${last_index})
            if(index LESS 10)
                set(feature_id "feature.00${index}")
            elseif(index LESS 100)
                set(feature_id "feature.0${index}")
            else()
                set(feature_id "feature.${index}")
            endif()

            set(header "${generated_dir}/function_${index}.h")
            set(source "${generated_dir}/function_${index}.cpp")

            file(WRITE "${header}" "#pragma once\n\n#include \"business_context.h\"\n#include \"ifunction.h\"\n\nclass Function${index} final : public IFunction\n{\npublic:\n    explicit Function${index}(BusinessContext& business) noexcept\n        : business_(business)\n    {\n    }\n\n    int execute(const FunctionInvocation& invocation) override;\n\nprivate:\n    BusinessContext& business_;\n};\n")

            file(WRITE "${source}" "#include \"function_${index}.h\"\n\n#include <memory>\n\nint Function${index}::execute(const FunctionInvocation& invocation)\n{\n    return business_.run(${index}, invocation.uiBias, invocation.checked);\n}\n\nstd::unique_ptr<IFunction> makeFunction${index}(BusinessContext& business)\n{\n    return std::make_unique<Function${index}>(business);\n}\n")

            string(APPEND factory_declarations "std::unique_ptr<IFunction> makeFunction${index}(BusinessContext& business);\n")
            string(APPEND register_entries "    allRegistered = registry.registerFunction(\"${feature_id}\", makeFunction${index}(business)) && allRegistered;\n")
            string(APPEND main_actions "    QAction action${index};\n    action${index}.setCheckable(true);\n    action${index}.setData(QStringLiteral(\"${feature_id}\"));\n    actionGroup.addAction(&action${index});\n    action${index}.trigger();\n")
            list(APPEND generated_sources "${header}" "${source}")
        endforeach()

        file(WRITE "${factories_header}" "${factory_declarations}")
        file(WRITE "${register_header}" [=[
#pragma once

class BusinessContext;
class FunctionRegistry;

bool registerAllFunctions(FunctionRegistry& registry, BusinessContext& business);
]=])
        file(WRITE "${register_source}" "#include \"register_all_functions.h\"\n\n#include \"function_factories.h\"\n#include \"function_registry.h\"\n\nbool registerAllFunctions(FunctionRegistry& registry, BusinessContext& business)\n{\n    bool allRegistered = true;\n${register_entries}    return allRegistered;\n}\n")

        if(last_index LESS 10)
            set(last_feature_id "feature.00${last_index}")
        elseif(last_index LESS 100)
            set(last_feature_id "feature.0${last_index}")
        else()
            set(last_feature_id "feature.${last_index}")
        endif()

        file(WRITE "${main_source}" "#include <QAction>\n#include <QActionGroup>\n#include <QApplication>\n#include <QString>\n\n#include <iostream>\n\n#include \"action_router.h\"\n#include \"business_context.h\"\n#include \"function_registry.h\"\n#include \"register_all_functions.h\"\n#include \"ui_context.h\"\n\nint main(int argc, char** argv)\n{\n    QApplication application(argc, argv);\n    BusinessContext business;\n    UiContext ui;\n    FunctionRegistry registry;\n\n    if (!registerAllFunctions(registry, business) || registry.size() != ${action_count})\n        return 3;\n    if (registerAllFunctions(registry, business) || registry.size() != ${action_count})\n        return 4;\n\n    RouterState state;\n    ActionRouter router(registry, ui, state);\n    QActionGroup actionGroup(&application);\n    actionGroup.setExclusive(false);\n    QObject::connect(\n        &actionGroup,\n        &QActionGroup::triggered,\n        &application,\n        [&router](QAction* action) { router.dispatch(action); });\n\n${main_actions}\n    constexpr long long expected = ${expected_checksum};\n    if (state.checksum != expected\n        || state.dispatchCount != ${action_count}\n        || state.failedDispatchCount != 0\n        || state.lastFunctionId != \"${last_feature_id}\")\n        return 5;\n\n    QAction unknownAction;\n    unknownAction.setData(QStringLiteral(\"feature.missing\"));\n    actionGroup.addAction(&unknownAction);\n    unknownAction.trigger();\n    if (state.checksum != expected\n        || state.dispatchCount != ${action_count}\n        || state.failedDispatchCount != 1\n        || state.lastFunctionId != \"feature.missing\")\n        return 6;\n\n    std::cout << \"variant=\" << BENCH_VARIANT_NAME\n              << \" count=${action_count} dispatches=\" << state.dispatchCount\n              << \" failed=\" << state.failedDispatchCount\n              << \" checksum=\" << state.checksum << '\\n';\n    return 0;\n}\n")

        list(APPEND generated_sources
            "${invocation_header}"
            "${interface_header}"
            "${registry_header}"
            "${registry_source}"
            "${router_header}"
            "${router_source}"
            "${factories_header}"
            "${register_header}"
            "${register_source}"
        )
    endif()

    list(APPEND generated_sources "${main_source}")
    set(${output_variable} "${generated_sources}" PARENT_SCOPE)
endfunction()
