#include "function_72.h"

#include <memory>

int Function72::execute(const FunctionInvocation& invocation)
{
    return business_.run(72, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction72(BusinessContext& business)
{
    return std::make_unique<Function72>(business);
}
