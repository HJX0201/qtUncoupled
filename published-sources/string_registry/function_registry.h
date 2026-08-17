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
