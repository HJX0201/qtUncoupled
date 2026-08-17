#include "function_14.h"

#include <memory>

int Function14::execute(const FunctionInvocation& invocation)
{
    return business_.run(14, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction14(BusinessContext& business)
{
    return std::make_unique<Function14>(business);
}
