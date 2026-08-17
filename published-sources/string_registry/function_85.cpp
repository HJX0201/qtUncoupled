#include "function_85.h"

#include <memory>

int Function85::execute(const FunctionInvocation& invocation)
{
    return business_.run(85, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction85(BusinessContext& business)
{
    return std::make_unique<Function85>(business);
}
