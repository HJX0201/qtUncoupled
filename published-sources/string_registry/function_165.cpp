#include "function_165.h"

#include <memory>

int Function165::execute(const FunctionInvocation& invocation)
{
    return business_.run(165, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction165(BusinessContext& business)
{
    return std::make_unique<Function165>(business);
}
