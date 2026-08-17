#include "function_103.h"

#include <memory>

int Function103::execute(const FunctionInvocation& invocation)
{
    return business_.run(103, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction103(BusinessContext& business)
{
    return std::make_unique<Function103>(business);
}
