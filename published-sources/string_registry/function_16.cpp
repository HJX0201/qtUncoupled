#include "function_16.h"

#include <memory>

int Function16::execute(const FunctionInvocation& invocation)
{
    return business_.run(16, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction16(BusinessContext& business)
{
    return std::make_unique<Function16>(business);
}
