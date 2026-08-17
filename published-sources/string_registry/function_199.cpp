#include "function_199.h"

#include <memory>

int Function199::execute(const FunctionInvocation& invocation)
{
    return business_.run(199, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction199(BusinessContext& business)
{
    return std::make_unique<Function199>(business);
}
