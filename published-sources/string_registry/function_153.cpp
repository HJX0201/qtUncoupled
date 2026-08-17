#include "function_153.h"

#include <memory>

int Function153::execute(const FunctionInvocation& invocation)
{
    return business_.run(153, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction153(BusinessContext& business)
{
    return std::make_unique<Function153>(business);
}
