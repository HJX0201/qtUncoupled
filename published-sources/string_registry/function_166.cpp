#include "function_166.h"

#include <memory>

int Function166::execute(const FunctionInvocation& invocation)
{
    return business_.run(166, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction166(BusinessContext& business)
{
    return std::make_unique<Function166>(business);
}
