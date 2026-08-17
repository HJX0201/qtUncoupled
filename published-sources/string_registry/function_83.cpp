#include "function_83.h"

#include <memory>

int Function83::execute(const FunctionInvocation& invocation)
{
    return business_.run(83, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction83(BusinessContext& business)
{
    return std::make_unique<Function83>(business);
}
