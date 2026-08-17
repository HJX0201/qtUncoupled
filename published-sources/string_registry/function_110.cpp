#include "function_110.h"

#include <memory>

int Function110::execute(const FunctionInvocation& invocation)
{
    return business_.run(110, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction110(BusinessContext& business)
{
    return std::make_unique<Function110>(business);
}
