#include "function_100.h"

#include <memory>

int Function100::execute(const FunctionInvocation& invocation)
{
    return business_.run(100, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction100(BusinessContext& business)
{
    return std::make_unique<Function100>(business);
}
