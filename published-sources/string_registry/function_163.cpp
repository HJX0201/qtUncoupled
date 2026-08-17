#include "function_163.h"

#include <memory>

int Function163::execute(const FunctionInvocation& invocation)
{
    return business_.run(163, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction163(BusinessContext& business)
{
    return std::make_unique<Function163>(business);
}
