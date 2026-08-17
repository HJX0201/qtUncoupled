#include "function_99.h"

#include <memory>

int Function99::execute(const FunctionInvocation& invocation)
{
    return business_.run(99, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction99(BusinessContext& business)
{
    return std::make_unique<Function99>(business);
}
