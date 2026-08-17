#include "function_178.h"

#include <memory>

int Function178::execute(const FunctionInvocation& invocation)
{
    return business_.run(178, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction178(BusinessContext& business)
{
    return std::make_unique<Function178>(business);
}
