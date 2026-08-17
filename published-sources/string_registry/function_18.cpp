#include "function_18.h"

#include <memory>

int Function18::execute(const FunctionInvocation& invocation)
{
    return business_.run(18, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction18(BusinessContext& business)
{
    return std::make_unique<Function18>(business);
}
