#include "function_115.h"

#include <memory>

int Function115::execute(const FunctionInvocation& invocation)
{
    return business_.run(115, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction115(BusinessContext& business)
{
    return std::make_unique<Function115>(business);
}
