#include "function_2.h"

#include <memory>

int Function2::execute(const FunctionInvocation& invocation)
{
    return business_.run(2, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction2(BusinessContext& business)
{
    return std::make_unique<Function2>(business);
}
