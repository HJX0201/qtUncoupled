#include "function_71.h"

#include <memory>

int Function71::execute(const FunctionInvocation& invocation)
{
    return business_.run(71, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction71(BusinessContext& business)
{
    return std::make_unique<Function71>(business);
}
