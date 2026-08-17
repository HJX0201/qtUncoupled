#include "function_74.h"

#include <memory>

int Function74::execute(const FunctionInvocation& invocation)
{
    return business_.run(74, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction74(BusinessContext& business)
{
    return std::make_unique<Function74>(business);
}
