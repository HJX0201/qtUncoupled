#include "function_23.h"

#include <memory>

int Function23::execute(const FunctionInvocation& invocation)
{
    return business_.run(23, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction23(BusinessContext& business)
{
    return std::make_unique<Function23>(business);
}
