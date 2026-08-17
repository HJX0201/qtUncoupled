#include "function_151.h"

#include <memory>

int Function151::execute(const FunctionInvocation& invocation)
{
    return business_.run(151, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction151(BusinessContext& business)
{
    return std::make_unique<Function151>(business);
}
