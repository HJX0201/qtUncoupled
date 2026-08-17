#include "function_118.h"

#include <memory>

int Function118::execute(const FunctionInvocation& invocation)
{
    return business_.run(118, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction118(BusinessContext& business)
{
    return std::make_unique<Function118>(business);
}
