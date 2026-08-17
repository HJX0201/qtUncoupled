#include "function_122.h"

#include <memory>

int Function122::execute(const FunctionInvocation& invocation)
{
    return business_.run(122, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction122(BusinessContext& business)
{
    return std::make_unique<Function122>(business);
}
