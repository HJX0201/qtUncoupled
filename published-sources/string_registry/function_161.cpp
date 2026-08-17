#include "function_161.h"

#include <memory>

int Function161::execute(const FunctionInvocation& invocation)
{
    return business_.run(161, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction161(BusinessContext& business)
{
    return std::make_unique<Function161>(business);
}
