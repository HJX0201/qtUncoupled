#include "function_38.h"

#include <memory>

int Function38::execute(const FunctionInvocation& invocation)
{
    return business_.run(38, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction38(BusinessContext& business)
{
    return std::make_unique<Function38>(business);
}
