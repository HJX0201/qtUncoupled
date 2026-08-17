#include "function_144.h"

#include <memory>

int Function144::execute(const FunctionInvocation& invocation)
{
    return business_.run(144, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction144(BusinessContext& business)
{
    return std::make_unique<Function144>(business);
}
