#include "function_150.h"

#include <memory>

int Function150::execute(const FunctionInvocation& invocation)
{
    return business_.run(150, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction150(BusinessContext& business)
{
    return std::make_unique<Function150>(business);
}
