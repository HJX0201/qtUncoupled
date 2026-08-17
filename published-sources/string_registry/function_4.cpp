#include "function_4.h"

#include <memory>

int Function4::execute(const FunctionInvocation& invocation)
{
    return business_.run(4, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction4(BusinessContext& business)
{
    return std::make_unique<Function4>(business);
}
