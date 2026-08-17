#include "function_183.h"

#include <memory>

int Function183::execute(const FunctionInvocation& invocation)
{
    return business_.run(183, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction183(BusinessContext& business)
{
    return std::make_unique<Function183>(business);
}
