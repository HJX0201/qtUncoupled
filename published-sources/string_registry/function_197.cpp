#include "function_197.h"

#include <memory>

int Function197::execute(const FunctionInvocation& invocation)
{
    return business_.run(197, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction197(BusinessContext& business)
{
    return std::make_unique<Function197>(business);
}
