#include "function_50.h"

#include <memory>

int Function50::execute(const FunctionInvocation& invocation)
{
    return business_.run(50, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction50(BusinessContext& business)
{
    return std::make_unique<Function50>(business);
}
