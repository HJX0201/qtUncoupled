#include "function_179.h"

#include <memory>

int Function179::execute(const FunctionInvocation& invocation)
{
    return business_.run(179, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction179(BusinessContext& business)
{
    return std::make_unique<Function179>(business);
}
