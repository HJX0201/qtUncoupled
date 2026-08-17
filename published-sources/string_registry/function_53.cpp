#include "function_53.h"

#include <memory>

int Function53::execute(const FunctionInvocation& invocation)
{
    return business_.run(53, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction53(BusinessContext& business)
{
    return std::make_unique<Function53>(business);
}
