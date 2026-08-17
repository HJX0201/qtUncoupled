#include "function_101.h"

#include <memory>

int Function101::execute(const FunctionInvocation& invocation)
{
    return business_.run(101, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction101(BusinessContext& business)
{
    return std::make_unique<Function101>(business);
}
