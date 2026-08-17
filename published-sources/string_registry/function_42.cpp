#include "function_42.h"

#include <memory>

int Function42::execute(const FunctionInvocation& invocation)
{
    return business_.run(42, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction42(BusinessContext& business)
{
    return std::make_unique<Function42>(business);
}
