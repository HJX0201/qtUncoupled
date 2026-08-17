#include "function_106.h"

#include <memory>

int Function106::execute(const FunctionInvocation& invocation)
{
    return business_.run(106, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction106(BusinessContext& business)
{
    return std::make_unique<Function106>(business);
}
