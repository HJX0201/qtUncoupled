#include "function_164.h"

#include <memory>

int Function164::execute(const FunctionInvocation& invocation)
{
    return business_.run(164, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction164(BusinessContext& business)
{
    return std::make_unique<Function164>(business);
}
