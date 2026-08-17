#include "function_5.h"

#include <memory>

int Function5::execute(const FunctionInvocation& invocation)
{
    return business_.run(5, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction5(BusinessContext& business)
{
    return std::make_unique<Function5>(business);
}
