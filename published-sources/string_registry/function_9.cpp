#include "function_9.h"

#include <memory>

int Function9::execute(const FunctionInvocation& invocation)
{
    return business_.run(9, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction9(BusinessContext& business)
{
    return std::make_unique<Function9>(business);
}
