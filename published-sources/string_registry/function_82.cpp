#include "function_82.h"

#include <memory>

int Function82::execute(const FunctionInvocation& invocation)
{
    return business_.run(82, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction82(BusinessContext& business)
{
    return std::make_unique<Function82>(business);
}
