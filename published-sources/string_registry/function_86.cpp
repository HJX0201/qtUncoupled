#include "function_86.h"

#include <memory>

int Function86::execute(const FunctionInvocation& invocation)
{
    return business_.run(86, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction86(BusinessContext& business)
{
    return std::make_unique<Function86>(business);
}
