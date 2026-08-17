#include "function_174.h"

#include <memory>

int Function174::execute(const FunctionInvocation& invocation)
{
    return business_.run(174, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction174(BusinessContext& business)
{
    return std::make_unique<Function174>(business);
}
