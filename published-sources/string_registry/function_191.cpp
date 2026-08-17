#include "function_191.h"

#include <memory>

int Function191::execute(const FunctionInvocation& invocation)
{
    return business_.run(191, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction191(BusinessContext& business)
{
    return std::make_unique<Function191>(business);
}
