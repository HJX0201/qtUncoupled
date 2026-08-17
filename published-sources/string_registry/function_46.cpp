#include "function_46.h"

#include <memory>

int Function46::execute(const FunctionInvocation& invocation)
{
    return business_.run(46, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction46(BusinessContext& business)
{
    return std::make_unique<Function46>(business);
}
