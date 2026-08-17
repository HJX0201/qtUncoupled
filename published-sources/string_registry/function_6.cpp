#include "function_6.h"

#include <memory>

int Function6::execute(const FunctionInvocation& invocation)
{
    return business_.run(6, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction6(BusinessContext& business)
{
    return std::make_unique<Function6>(business);
}
