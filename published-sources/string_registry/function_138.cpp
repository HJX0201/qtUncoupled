#include "function_138.h"

#include <memory>

int Function138::execute(const FunctionInvocation& invocation)
{
    return business_.run(138, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction138(BusinessContext& business)
{
    return std::make_unique<Function138>(business);
}
