#include "function_168.h"

#include <memory>

int Function168::execute(const FunctionInvocation& invocation)
{
    return business_.run(168, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction168(BusinessContext& business)
{
    return std::make_unique<Function168>(business);
}
