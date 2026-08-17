#include "function_0.h"

#include <memory>

int Function0::execute(const FunctionInvocation& invocation)
{
    return business_.run(0, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction0(BusinessContext& business)
{
    return std::make_unique<Function0>(business);
}
