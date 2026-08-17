#include "function_91.h"

#include <memory>

int Function91::execute(const FunctionInvocation& invocation)
{
    return business_.run(91, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction91(BusinessContext& business)
{
    return std::make_unique<Function91>(business);
}
