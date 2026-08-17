#include "function_142.h"

#include <memory>

int Function142::execute(const FunctionInvocation& invocation)
{
    return business_.run(142, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction142(BusinessContext& business)
{
    return std::make_unique<Function142>(business);
}
