#include "function_130.h"

#include <memory>

int Function130::execute(const FunctionInvocation& invocation)
{
    return business_.run(130, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction130(BusinessContext& business)
{
    return std::make_unique<Function130>(business);
}
