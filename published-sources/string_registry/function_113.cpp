#include "function_113.h"

#include <memory>

int Function113::execute(const FunctionInvocation& invocation)
{
    return business_.run(113, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction113(BusinessContext& business)
{
    return std::make_unique<Function113>(business);
}
