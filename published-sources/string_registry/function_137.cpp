#include "function_137.h"

#include <memory>

int Function137::execute(const FunctionInvocation& invocation)
{
    return business_.run(137, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction137(BusinessContext& business)
{
    return std::make_unique<Function137>(business);
}
