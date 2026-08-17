#include "function_131.h"

#include <memory>

int Function131::execute(const FunctionInvocation& invocation)
{
    return business_.run(131, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction131(BusinessContext& business)
{
    return std::make_unique<Function131>(business);
}
