#include "function_117.h"

#include <memory>

int Function117::execute(const FunctionInvocation& invocation)
{
    return business_.run(117, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction117(BusinessContext& business)
{
    return std::make_unique<Function117>(business);
}
