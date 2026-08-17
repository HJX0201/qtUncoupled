#include "function_127.h"

#include <memory>

int Function127::execute(const FunctionInvocation& invocation)
{
    return business_.run(127, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction127(BusinessContext& business)
{
    return std::make_unique<Function127>(business);
}
