#include "function_51.h"

#include <memory>

int Function51::execute(const FunctionInvocation& invocation)
{
    return business_.run(51, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction51(BusinessContext& business)
{
    return std::make_unique<Function51>(business);
}
