#include "function_39.h"

#include <memory>

int Function39::execute(const FunctionInvocation& invocation)
{
    return business_.run(39, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction39(BusinessContext& business)
{
    return std::make_unique<Function39>(business);
}
