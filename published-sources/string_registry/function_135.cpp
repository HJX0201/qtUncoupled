#include "function_135.h"

#include <memory>

int Function135::execute(const FunctionInvocation& invocation)
{
    return business_.run(135, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction135(BusinessContext& business)
{
    return std::make_unique<Function135>(business);
}
