#include "function_75.h"

#include <memory>

int Function75::execute(const FunctionInvocation& invocation)
{
    return business_.run(75, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction75(BusinessContext& business)
{
    return std::make_unique<Function75>(business);
}
