#include "function_159.h"

#include <memory>

int Function159::execute(const FunctionInvocation& invocation)
{
    return business_.run(159, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction159(BusinessContext& business)
{
    return std::make_unique<Function159>(business);
}
