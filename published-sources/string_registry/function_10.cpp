#include "function_10.h"

#include <memory>

int Function10::execute(const FunctionInvocation& invocation)
{
    return business_.run(10, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction10(BusinessContext& business)
{
    return std::make_unique<Function10>(business);
}
