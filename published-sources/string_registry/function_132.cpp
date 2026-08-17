#include "function_132.h"

#include <memory>

int Function132::execute(const FunctionInvocation& invocation)
{
    return business_.run(132, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction132(BusinessContext& business)
{
    return std::make_unique<Function132>(business);
}
