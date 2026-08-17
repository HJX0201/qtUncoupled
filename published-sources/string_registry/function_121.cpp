#include "function_121.h"

#include <memory>

int Function121::execute(const FunctionInvocation& invocation)
{
    return business_.run(121, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction121(BusinessContext& business)
{
    return std::make_unique<Function121>(business);
}
