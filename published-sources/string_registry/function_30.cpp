#include "function_30.h"

#include <memory>

int Function30::execute(const FunctionInvocation& invocation)
{
    return business_.run(30, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction30(BusinessContext& business)
{
    return std::make_unique<Function30>(business);
}
