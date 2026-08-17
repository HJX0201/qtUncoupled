#include "function_65.h"

#include <memory>

int Function65::execute(const FunctionInvocation& invocation)
{
    return business_.run(65, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction65(BusinessContext& business)
{
    return std::make_unique<Function65>(business);
}
