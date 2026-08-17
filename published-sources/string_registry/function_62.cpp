#include "function_62.h"

#include <memory>

int Function62::execute(const FunctionInvocation& invocation)
{
    return business_.run(62, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction62(BusinessContext& business)
{
    return std::make_unique<Function62>(business);
}
