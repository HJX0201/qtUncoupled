#include "function_90.h"

#include <memory>

int Function90::execute(const FunctionInvocation& invocation)
{
    return business_.run(90, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction90(BusinessContext& business)
{
    return std::make_unique<Function90>(business);
}
