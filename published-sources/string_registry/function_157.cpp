#include "function_157.h"

#include <memory>

int Function157::execute(const FunctionInvocation& invocation)
{
    return business_.run(157, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction157(BusinessContext& business)
{
    return std::make_unique<Function157>(business);
}
