#include "function_67.h"

#include <memory>

int Function67::execute(const FunctionInvocation& invocation)
{
    return business_.run(67, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction67(BusinessContext& business)
{
    return std::make_unique<Function67>(business);
}
