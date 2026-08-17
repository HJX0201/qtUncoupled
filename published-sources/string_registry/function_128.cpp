#include "function_128.h"

#include <memory>

int Function128::execute(const FunctionInvocation& invocation)
{
    return business_.run(128, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction128(BusinessContext& business)
{
    return std::make_unique<Function128>(business);
}
