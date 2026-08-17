#include "function_158.h"

#include <memory>

int Function158::execute(const FunctionInvocation& invocation)
{
    return business_.run(158, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction158(BusinessContext& business)
{
    return std::make_unique<Function158>(business);
}
