#include "function_133.h"

#include <memory>

int Function133::execute(const FunctionInvocation& invocation)
{
    return business_.run(133, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction133(BusinessContext& business)
{
    return std::make_unique<Function133>(business);
}
