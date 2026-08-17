#include "function_182.h"

#include <memory>

int Function182::execute(const FunctionInvocation& invocation)
{
    return business_.run(182, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction182(BusinessContext& business)
{
    return std::make_unique<Function182>(business);
}
