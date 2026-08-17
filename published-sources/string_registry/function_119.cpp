#include "function_119.h"

#include <memory>

int Function119::execute(const FunctionInvocation& invocation)
{
    return business_.run(119, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction119(BusinessContext& business)
{
    return std::make_unique<Function119>(business);
}
