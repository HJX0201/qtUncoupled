#include "function_140.h"

#include <memory>

int Function140::execute(const FunctionInvocation& invocation)
{
    return business_.run(140, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction140(BusinessContext& business)
{
    return std::make_unique<Function140>(business);
}
