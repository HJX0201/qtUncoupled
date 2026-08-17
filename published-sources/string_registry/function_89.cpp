#include "function_89.h"

#include <memory>

int Function89::execute(const FunctionInvocation& invocation)
{
    return business_.run(89, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction89(BusinessContext& business)
{
    return std::make_unique<Function89>(business);
}
