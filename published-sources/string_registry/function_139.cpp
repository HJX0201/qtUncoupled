#include "function_139.h"

#include <memory>

int Function139::execute(const FunctionInvocation& invocation)
{
    return business_.run(139, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction139(BusinessContext& business)
{
    return std::make_unique<Function139>(business);
}
