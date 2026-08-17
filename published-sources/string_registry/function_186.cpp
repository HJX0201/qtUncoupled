#include "function_186.h"

#include <memory>

int Function186::execute(const FunctionInvocation& invocation)
{
    return business_.run(186, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction186(BusinessContext& business)
{
    return std::make_unique<Function186>(business);
}
