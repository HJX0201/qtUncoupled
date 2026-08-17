#include "function_58.h"

#include <memory>

int Function58::execute(const FunctionInvocation& invocation)
{
    return business_.run(58, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction58(BusinessContext& business)
{
    return std::make_unique<Function58>(business);
}
