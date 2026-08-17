#include "function_116.h"

#include <memory>

int Function116::execute(const FunctionInvocation& invocation)
{
    return business_.run(116, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction116(BusinessContext& business)
{
    return std::make_unique<Function116>(business);
}
