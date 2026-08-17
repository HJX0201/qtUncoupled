#include "function_177.h"

#include <memory>

int Function177::execute(const FunctionInvocation& invocation)
{
    return business_.run(177, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction177(BusinessContext& business)
{
    return std::make_unique<Function177>(business);
}
