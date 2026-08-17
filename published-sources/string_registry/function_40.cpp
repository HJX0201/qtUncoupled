#include "function_40.h"

#include <memory>

int Function40::execute(const FunctionInvocation& invocation)
{
    return business_.run(40, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction40(BusinessContext& business)
{
    return std::make_unique<Function40>(business);
}
