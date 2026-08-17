#include "function_54.h"

#include <memory>

int Function54::execute(const FunctionInvocation& invocation)
{
    return business_.run(54, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction54(BusinessContext& business)
{
    return std::make_unique<Function54>(business);
}
