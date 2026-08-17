#include "function_66.h"

#include <memory>

int Function66::execute(const FunctionInvocation& invocation)
{
    return business_.run(66, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction66(BusinessContext& business)
{
    return std::make_unique<Function66>(business);
}
