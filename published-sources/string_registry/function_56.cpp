#include "function_56.h"

#include <memory>

int Function56::execute(const FunctionInvocation& invocation)
{
    return business_.run(56, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction56(BusinessContext& business)
{
    return std::make_unique<Function56>(business);
}
