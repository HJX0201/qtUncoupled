#include "function_87.h"

#include <memory>

int Function87::execute(const FunctionInvocation& invocation)
{
    return business_.run(87, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction87(BusinessContext& business)
{
    return std::make_unique<Function87>(business);
}
