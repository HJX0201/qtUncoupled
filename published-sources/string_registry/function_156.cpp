#include "function_156.h"

#include <memory>

int Function156::execute(const FunctionInvocation& invocation)
{
    return business_.run(156, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction156(BusinessContext& business)
{
    return std::make_unique<Function156>(business);
}
