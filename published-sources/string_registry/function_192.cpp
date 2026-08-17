#include "function_192.h"

#include <memory>

int Function192::execute(const FunctionInvocation& invocation)
{
    return business_.run(192, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction192(BusinessContext& business)
{
    return std::make_unique<Function192>(business);
}
