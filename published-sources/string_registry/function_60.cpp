#include "function_60.h"

#include <memory>

int Function60::execute(const FunctionInvocation& invocation)
{
    return business_.run(60, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction60(BusinessContext& business)
{
    return std::make_unique<Function60>(business);
}
