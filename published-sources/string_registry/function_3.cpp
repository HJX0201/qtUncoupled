#include "function_3.h"

#include <memory>

int Function3::execute(const FunctionInvocation& invocation)
{
    return business_.run(3, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction3(BusinessContext& business)
{
    return std::make_unique<Function3>(business);
}
