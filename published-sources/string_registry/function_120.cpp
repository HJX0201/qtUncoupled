#include "function_120.h"

#include <memory>

int Function120::execute(const FunctionInvocation& invocation)
{
    return business_.run(120, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction120(BusinessContext& business)
{
    return std::make_unique<Function120>(business);
}
