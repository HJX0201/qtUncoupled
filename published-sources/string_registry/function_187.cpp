#include "function_187.h"

#include <memory>

int Function187::execute(const FunctionInvocation& invocation)
{
    return business_.run(187, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction187(BusinessContext& business)
{
    return std::make_unique<Function187>(business);
}
