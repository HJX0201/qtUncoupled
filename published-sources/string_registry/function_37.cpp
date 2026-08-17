#include "function_37.h"

#include <memory>

int Function37::execute(const FunctionInvocation& invocation)
{
    return business_.run(37, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction37(BusinessContext& business)
{
    return std::make_unique<Function37>(business);
}
