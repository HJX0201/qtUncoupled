#include "function_134.h"

#include <memory>

int Function134::execute(const FunctionInvocation& invocation)
{
    return business_.run(134, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction134(BusinessContext& business)
{
    return std::make_unique<Function134>(business);
}
