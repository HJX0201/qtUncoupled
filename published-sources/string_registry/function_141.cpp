#include "function_141.h"

#include <memory>

int Function141::execute(const FunctionInvocation& invocation)
{
    return business_.run(141, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction141(BusinessContext& business)
{
    return std::make_unique<Function141>(business);
}
