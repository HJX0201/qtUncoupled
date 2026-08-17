#include "function_26.h"

#include <memory>

int Function26::execute(const FunctionInvocation& invocation)
{
    return business_.run(26, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction26(BusinessContext& business)
{
    return std::make_unique<Function26>(business);
}
