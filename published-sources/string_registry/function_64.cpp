#include "function_64.h"

#include <memory>

int Function64::execute(const FunctionInvocation& invocation)
{
    return business_.run(64, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction64(BusinessContext& business)
{
    return std::make_unique<Function64>(business);
}
