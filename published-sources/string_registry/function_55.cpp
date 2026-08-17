#include "function_55.h"

#include <memory>

int Function55::execute(const FunctionInvocation& invocation)
{
    return business_.run(55, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction55(BusinessContext& business)
{
    return std::make_unique<Function55>(business);
}
