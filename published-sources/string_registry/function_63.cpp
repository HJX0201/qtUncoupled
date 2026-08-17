#include "function_63.h"

#include <memory>

int Function63::execute(const FunctionInvocation& invocation)
{
    return business_.run(63, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction63(BusinessContext& business)
{
    return std::make_unique<Function63>(business);
}
