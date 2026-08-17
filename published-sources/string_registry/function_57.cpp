#include "function_57.h"

#include <memory>

int Function57::execute(const FunctionInvocation& invocation)
{
    return business_.run(57, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction57(BusinessContext& business)
{
    return std::make_unique<Function57>(business);
}
