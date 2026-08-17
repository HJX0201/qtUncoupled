#include "function_181.h"

#include <memory>

int Function181::execute(const FunctionInvocation& invocation)
{
    return business_.run(181, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction181(BusinessContext& business)
{
    return std::make_unique<Function181>(business);
}
