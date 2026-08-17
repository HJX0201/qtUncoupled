#include "function_98.h"

#include <memory>

int Function98::execute(const FunctionInvocation& invocation)
{
    return business_.run(98, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction98(BusinessContext& business)
{
    return std::make_unique<Function98>(business);
}
