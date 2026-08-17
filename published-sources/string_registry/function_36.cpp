#include "function_36.h"

#include <memory>

int Function36::execute(const FunctionInvocation& invocation)
{
    return business_.run(36, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction36(BusinessContext& business)
{
    return std::make_unique<Function36>(business);
}
