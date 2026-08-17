#include "function_125.h"

#include <memory>

int Function125::execute(const FunctionInvocation& invocation)
{
    return business_.run(125, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction125(BusinessContext& business)
{
    return std::make_unique<Function125>(business);
}
