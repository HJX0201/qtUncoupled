#include "function_21.h"

#include <memory>

int Function21::execute(const FunctionInvocation& invocation)
{
    return business_.run(21, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction21(BusinessContext& business)
{
    return std::make_unique<Function21>(business);
}
