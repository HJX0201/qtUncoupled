#include "function_146.h"

#include <memory>

int Function146::execute(const FunctionInvocation& invocation)
{
    return business_.run(146, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction146(BusinessContext& business)
{
    return std::make_unique<Function146>(business);
}
