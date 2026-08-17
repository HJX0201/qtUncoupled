#include "function_155.h"

#include <memory>

int Function155::execute(const FunctionInvocation& invocation)
{
    return business_.run(155, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction155(BusinessContext& business)
{
    return std::make_unique<Function155>(business);
}
