#include "function_194.h"

#include <memory>

int Function194::execute(const FunctionInvocation& invocation)
{
    return business_.run(194, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction194(BusinessContext& business)
{
    return std::make_unique<Function194>(business);
}
