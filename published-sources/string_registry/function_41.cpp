#include "function_41.h"

#include <memory>

int Function41::execute(const FunctionInvocation& invocation)
{
    return business_.run(41, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction41(BusinessContext& business)
{
    return std::make_unique<Function41>(business);
}
