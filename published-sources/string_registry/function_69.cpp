#include "function_69.h"

#include <memory>

int Function69::execute(const FunctionInvocation& invocation)
{
    return business_.run(69, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction69(BusinessContext& business)
{
    return std::make_unique<Function69>(business);
}
