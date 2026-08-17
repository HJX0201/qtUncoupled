#include "function_15.h"

#include <memory>

int Function15::execute(const FunctionInvocation& invocation)
{
    return business_.run(15, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction15(BusinessContext& business)
{
    return std::make_unique<Function15>(business);
}
