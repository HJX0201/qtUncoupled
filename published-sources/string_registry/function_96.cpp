#include "function_96.h"

#include <memory>

int Function96::execute(const FunctionInvocation& invocation)
{
    return business_.run(96, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction96(BusinessContext& business)
{
    return std::make_unique<Function96>(business);
}
