#include "function_111.h"

#include <memory>

int Function111::execute(const FunctionInvocation& invocation)
{
    return business_.run(111, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction111(BusinessContext& business)
{
    return std::make_unique<Function111>(business);
}
