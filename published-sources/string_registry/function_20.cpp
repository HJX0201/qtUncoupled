#include "function_20.h"

#include <memory>

int Function20::execute(const FunctionInvocation& invocation)
{
    return business_.run(20, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction20(BusinessContext& business)
{
    return std::make_unique<Function20>(business);
}
