#include "function_162.h"

#include <memory>

int Function162::execute(const FunctionInvocation& invocation)
{
    return business_.run(162, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction162(BusinessContext& business)
{
    return std::make_unique<Function162>(business);
}
