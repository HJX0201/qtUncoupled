#include "function_45.h"

#include <memory>

int Function45::execute(const FunctionInvocation& invocation)
{
    return business_.run(45, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction45(BusinessContext& business)
{
    return std::make_unique<Function45>(business);
}
