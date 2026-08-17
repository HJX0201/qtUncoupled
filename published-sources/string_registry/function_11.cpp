#include "function_11.h"

#include <memory>

int Function11::execute(const FunctionInvocation& invocation)
{
    return business_.run(11, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction11(BusinessContext& business)
{
    return std::make_unique<Function11>(business);
}
