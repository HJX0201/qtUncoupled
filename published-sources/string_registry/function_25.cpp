#include "function_25.h"

#include <memory>

int Function25::execute(const FunctionInvocation& invocation)
{
    return business_.run(25, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction25(BusinessContext& business)
{
    return std::make_unique<Function25>(business);
}
