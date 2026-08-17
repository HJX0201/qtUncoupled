#include "function_47.h"

#include <memory>

int Function47::execute(const FunctionInvocation& invocation)
{
    return business_.run(47, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction47(BusinessContext& business)
{
    return std::make_unique<Function47>(business);
}
