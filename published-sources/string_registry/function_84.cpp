#include "function_84.h"

#include <memory>

int Function84::execute(const FunctionInvocation& invocation)
{
    return business_.run(84, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction84(BusinessContext& business)
{
    return std::make_unique<Function84>(business);
}
