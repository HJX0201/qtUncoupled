#include "function_149.h"

#include <memory>

int Function149::execute(const FunctionInvocation& invocation)
{
    return business_.run(149, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction149(BusinessContext& business)
{
    return std::make_unique<Function149>(business);
}
