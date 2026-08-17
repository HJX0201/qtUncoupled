#include "function_114.h"

#include <memory>

int Function114::execute(const FunctionInvocation& invocation)
{
    return business_.run(114, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction114(BusinessContext& business)
{
    return std::make_unique<Function114>(business);
}
