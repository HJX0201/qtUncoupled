#include "function_8.h"

#include <memory>

int Function8::execute(const FunctionInvocation& invocation)
{
    return business_.run(8, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction8(BusinessContext& business)
{
    return std::make_unique<Function8>(business);
}
