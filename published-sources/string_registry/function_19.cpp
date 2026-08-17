#include "function_19.h"

#include <memory>

int Function19::execute(const FunctionInvocation& invocation)
{
    return business_.run(19, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction19(BusinessContext& business)
{
    return std::make_unique<Function19>(business);
}
