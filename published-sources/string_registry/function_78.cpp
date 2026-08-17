#include "function_78.h"

#include <memory>

int Function78::execute(const FunctionInvocation& invocation)
{
    return business_.run(78, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction78(BusinessContext& business)
{
    return std::make_unique<Function78>(business);
}
