#include "function_170.h"

#include <memory>

int Function170::execute(const FunctionInvocation& invocation)
{
    return business_.run(170, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction170(BusinessContext& business)
{
    return std::make_unique<Function170>(business);
}
