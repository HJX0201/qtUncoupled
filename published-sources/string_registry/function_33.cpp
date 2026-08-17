#include "function_33.h"

#include <memory>

int Function33::execute(const FunctionInvocation& invocation)
{
    return business_.run(33, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction33(BusinessContext& business)
{
    return std::make_unique<Function33>(business);
}
