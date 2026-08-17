#include "function_198.h"

#include <memory>

int Function198::execute(const FunctionInvocation& invocation)
{
    return business_.run(198, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction198(BusinessContext& business)
{
    return std::make_unique<Function198>(business);
}
