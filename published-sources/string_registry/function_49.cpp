#include "function_49.h"

#include <memory>

int Function49::execute(const FunctionInvocation& invocation)
{
    return business_.run(49, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction49(BusinessContext& business)
{
    return std::make_unique<Function49>(business);
}
