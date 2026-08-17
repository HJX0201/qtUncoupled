#include "function_102.h"

#include <memory>

int Function102::execute(const FunctionInvocation& invocation)
{
    return business_.run(102, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction102(BusinessContext& business)
{
    return std::make_unique<Function102>(business);
}
