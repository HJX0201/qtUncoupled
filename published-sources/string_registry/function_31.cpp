#include "function_31.h"

#include <memory>

int Function31::execute(const FunctionInvocation& invocation)
{
    return business_.run(31, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction31(BusinessContext& business)
{
    return std::make_unique<Function31>(business);
}
