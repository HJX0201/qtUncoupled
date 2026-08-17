#include "function_107.h"

#include <memory>

int Function107::execute(const FunctionInvocation& invocation)
{
    return business_.run(107, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction107(BusinessContext& business)
{
    return std::make_unique<Function107>(business);
}
