#include "function_93.h"

#include <memory>

int Function93::execute(const FunctionInvocation& invocation)
{
    return business_.run(93, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction93(BusinessContext& business)
{
    return std::make_unique<Function93>(business);
}
