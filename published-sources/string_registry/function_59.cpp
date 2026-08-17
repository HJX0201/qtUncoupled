#include "function_59.h"

#include <memory>

int Function59::execute(const FunctionInvocation& invocation)
{
    return business_.run(59, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction59(BusinessContext& business)
{
    return std::make_unique<Function59>(business);
}
