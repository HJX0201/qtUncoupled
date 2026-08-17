#include "function_109.h"

#include <memory>

int Function109::execute(const FunctionInvocation& invocation)
{
    return business_.run(109, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction109(BusinessContext& business)
{
    return std::make_unique<Function109>(business);
}
