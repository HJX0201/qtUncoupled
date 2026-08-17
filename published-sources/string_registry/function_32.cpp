#include "function_32.h"

#include <memory>

int Function32::execute(const FunctionInvocation& invocation)
{
    return business_.run(32, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction32(BusinessContext& business)
{
    return std::make_unique<Function32>(business);
}
