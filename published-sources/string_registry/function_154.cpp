#include "function_154.h"

#include <memory>

int Function154::execute(const FunctionInvocation& invocation)
{
    return business_.run(154, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction154(BusinessContext& business)
{
    return std::make_unique<Function154>(business);
}
