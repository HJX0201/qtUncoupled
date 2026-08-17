#include "function_28.h"

#include <memory>

int Function28::execute(const FunctionInvocation& invocation)
{
    return business_.run(28, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction28(BusinessContext& business)
{
    return std::make_unique<Function28>(business);
}
