#include "function_143.h"

#include <memory>

int Function143::execute(const FunctionInvocation& invocation)
{
    return business_.run(143, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction143(BusinessContext& business)
{
    return std::make_unique<Function143>(business);
}
