#include "function_81.h"

#include <memory>

int Function81::execute(const FunctionInvocation& invocation)
{
    return business_.run(81, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction81(BusinessContext& business)
{
    return std::make_unique<Function81>(business);
}
