#include "function_12.h"

#include <memory>

int Function12::execute(const FunctionInvocation& invocation)
{
    return business_.run(12, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction12(BusinessContext& business)
{
    return std::make_unique<Function12>(business);
}
