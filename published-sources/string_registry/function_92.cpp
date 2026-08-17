#include "function_92.h"

#include <memory>

int Function92::execute(const FunctionInvocation& invocation)
{
    return business_.run(92, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction92(BusinessContext& business)
{
    return std::make_unique<Function92>(business);
}
