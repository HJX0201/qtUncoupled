#include "function_97.h"

#include <memory>

int Function97::execute(const FunctionInvocation& invocation)
{
    return business_.run(97, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction97(BusinessContext& business)
{
    return std::make_unique<Function97>(business);
}
