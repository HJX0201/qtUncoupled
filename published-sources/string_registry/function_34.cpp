#include "function_34.h"

#include <memory>

int Function34::execute(const FunctionInvocation& invocation)
{
    return business_.run(34, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction34(BusinessContext& business)
{
    return std::make_unique<Function34>(business);
}
