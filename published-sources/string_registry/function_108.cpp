#include "function_108.h"

#include <memory>

int Function108::execute(const FunctionInvocation& invocation)
{
    return business_.run(108, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction108(BusinessContext& business)
{
    return std::make_unique<Function108>(business);
}
