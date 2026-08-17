#include "function_184.h"

#include <memory>

int Function184::execute(const FunctionInvocation& invocation)
{
    return business_.run(184, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction184(BusinessContext& business)
{
    return std::make_unique<Function184>(business);
}
