#include "function_43.h"

#include <memory>

int Function43::execute(const FunctionInvocation& invocation)
{
    return business_.run(43, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction43(BusinessContext& business)
{
    return std::make_unique<Function43>(business);
}
