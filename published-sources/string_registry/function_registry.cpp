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
