#include "function_61.h"

#include <memory>

int Function61::execute(const FunctionInvocation& invocation)
{
    return business_.run(61, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction61(BusinessContext& business)
{
    return std::make_unique<Function61>(business);
}
