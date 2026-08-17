#include "function_105.h"

#include <memory>

int Function105::execute(const FunctionInvocation& invocation)
{
    return business_.run(105, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction105(BusinessContext& business)
{
    return std::make_unique<Function105>(business);
}
