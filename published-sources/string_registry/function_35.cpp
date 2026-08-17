#include "function_35.h"

#include <memory>

int Function35::execute(const FunctionInvocation& invocation)
{
    return business_.run(35, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction35(BusinessContext& business)
{
    return std::make_unique<Function35>(business);
}
