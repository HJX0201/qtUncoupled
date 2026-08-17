#include "function_24.h"

#include <memory>

int Function24::execute(const FunctionInvocation& invocation)
{
    return business_.run(24, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction24(BusinessContext& business)
{
    return std::make_unique<Function24>(business);
}
