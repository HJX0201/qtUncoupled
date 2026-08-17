#include "function_22.h"

#include <memory>

int Function22::execute(const FunctionInvocation& invocation)
{
    return business_.run(22, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction22(BusinessContext& business)
{
    return std::make_unique<Function22>(business);
}
