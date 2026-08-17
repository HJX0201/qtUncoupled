#include "function_7.h"

#include <memory>

int Function7::execute(const FunctionInvocation& invocation)
{
    return business_.run(7, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction7(BusinessContext& business)
{
    return std::make_unique<Function7>(business);
}
