#include "function_123.h"

#include <memory>

int Function123::execute(const FunctionInvocation& invocation)
{
    return business_.run(123, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction123(BusinessContext& business)
{
    return std::make_unique<Function123>(business);
}
