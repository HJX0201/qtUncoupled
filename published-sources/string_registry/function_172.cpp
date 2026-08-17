#include "function_172.h"

#include <memory>

int Function172::execute(const FunctionInvocation& invocation)
{
    return business_.run(172, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction172(BusinessContext& business)
{
    return std::make_unique<Function172>(business);
}
