#include "function_175.h"

#include <memory>

int Function175::execute(const FunctionInvocation& invocation)
{
    return business_.run(175, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction175(BusinessContext& business)
{
    return std::make_unique<Function175>(business);
}
