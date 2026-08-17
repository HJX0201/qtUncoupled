#include "function_68.h"

#include <memory>

int Function68::execute(const FunctionInvocation& invocation)
{
    return business_.run(68, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction68(BusinessContext& business)
{
    return std::make_unique<Function68>(business);
}
