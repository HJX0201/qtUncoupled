#include "function_188.h"

#include <memory>

int Function188::execute(const FunctionInvocation& invocation)
{
    return business_.run(188, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction188(BusinessContext& business)
{
    return std::make_unique<Function188>(business);
}
