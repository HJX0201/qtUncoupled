#include "function_1.h"

#include <memory>

int Function1::execute(const FunctionInvocation& invocation)
{
    return business_.run(1, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction1(BusinessContext& business)
{
    return std::make_unique<Function1>(business);
}
