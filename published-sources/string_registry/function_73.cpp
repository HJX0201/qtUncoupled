#include "function_73.h"

#include <memory>

int Function73::execute(const FunctionInvocation& invocation)
{
    return business_.run(73, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction73(BusinessContext& business)
{
    return std::make_unique<Function73>(business);
}
