#include "function_124.h"

#include <memory>

int Function124::execute(const FunctionInvocation& invocation)
{
    return business_.run(124, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction124(BusinessContext& business)
{
    return std::make_unique<Function124>(business);
}
