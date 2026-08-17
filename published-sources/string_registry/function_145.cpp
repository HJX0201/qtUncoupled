#include "function_145.h"

#include <memory>

int Function145::execute(const FunctionInvocation& invocation)
{
    return business_.run(145, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction145(BusinessContext& business)
{
    return std::make_unique<Function145>(business);
}
