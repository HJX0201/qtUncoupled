#include "function_52.h"

#include <memory>

int Function52::execute(const FunctionInvocation& invocation)
{
    return business_.run(52, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction52(BusinessContext& business)
{
    return std::make_unique<Function52>(business);
}
