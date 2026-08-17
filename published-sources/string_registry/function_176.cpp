#include "function_176.h"

#include <memory>

int Function176::execute(const FunctionInvocation& invocation)
{
    return business_.run(176, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction176(BusinessContext& business)
{
    return std::make_unique<Function176>(business);
}
