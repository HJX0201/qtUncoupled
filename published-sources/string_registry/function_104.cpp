#include "function_104.h"

#include <memory>

int Function104::execute(const FunctionInvocation& invocation)
{
    return business_.run(104, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction104(BusinessContext& business)
{
    return std::make_unique<Function104>(business);
}
