#include "function_17.h"

#include <memory>

int Function17::execute(const FunctionInvocation& invocation)
{
    return business_.run(17, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction17(BusinessContext& business)
{
    return std::make_unique<Function17>(business);
}
