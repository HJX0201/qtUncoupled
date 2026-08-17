#include "function_76.h"

#include <memory>

int Function76::execute(const FunctionInvocation& invocation)
{
    return business_.run(76, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction76(BusinessContext& business)
{
    return std::make_unique<Function76>(business);
}
