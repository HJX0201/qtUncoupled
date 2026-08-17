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
