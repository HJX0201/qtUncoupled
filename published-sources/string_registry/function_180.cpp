#include "function_180.h"

#include <memory>

int Function180::execute(const FunctionInvocation& invocation)
{
    return business_.run(180, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction180(BusinessContext& business)
{
    return std::make_unique<Function180>(business);
}
