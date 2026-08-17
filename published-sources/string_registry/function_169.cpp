#include "function_169.h"

#include <memory>

int Function169::execute(const FunctionInvocation& invocation)
{
    return business_.run(169, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction169(BusinessContext& business)
{
    return std::make_unique<Function169>(business);
}
