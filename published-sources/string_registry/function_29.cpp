#include "function_29.h"

#include <memory>

int Function29::execute(const FunctionInvocation& invocation)
{
    return business_.run(29, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction29(BusinessContext& business)
{
    return std::make_unique<Function29>(business);
}
