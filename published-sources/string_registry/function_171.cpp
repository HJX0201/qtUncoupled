#include "function_171.h"

#include <memory>

int Function171::execute(const FunctionInvocation& invocation)
{
    return business_.run(171, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction171(BusinessContext& business)
{
    return std::make_unique<Function171>(business);
}
