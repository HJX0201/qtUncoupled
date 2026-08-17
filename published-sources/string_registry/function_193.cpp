#include "function_193.h"

#include <memory>

int Function193::execute(const FunctionInvocation& invocation)
{
    return business_.run(193, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction193(BusinessContext& business)
{
    return std::make_unique<Function193>(business);
}
