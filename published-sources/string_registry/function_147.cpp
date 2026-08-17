#include "function_147.h"

#include <memory>

int Function147::execute(const FunctionInvocation& invocation)
{
    return business_.run(147, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction147(BusinessContext& business)
{
    return std::make_unique<Function147>(business);
}
