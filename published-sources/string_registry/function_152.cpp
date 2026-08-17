#include "function_152.h"

#include <memory>

int Function152::execute(const FunctionInvocation& invocation)
{
    return business_.run(152, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction152(BusinessContext& business)
{
    return std::make_unique<Function152>(business);
}
