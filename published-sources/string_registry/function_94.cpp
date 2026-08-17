#include "function_94.h"

#include <memory>

int Function94::execute(const FunctionInvocation& invocation)
{
    return business_.run(94, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction94(BusinessContext& business)
{
    return std::make_unique<Function94>(business);
}
