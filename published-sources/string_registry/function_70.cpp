#include "function_70.h"

#include <memory>

int Function70::execute(const FunctionInvocation& invocation)
{
    return business_.run(70, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction70(BusinessContext& business)
{
    return std::make_unique<Function70>(business);
}
