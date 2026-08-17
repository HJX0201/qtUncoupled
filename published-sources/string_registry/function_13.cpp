#include "function_13.h"

#include <memory>

int Function13::execute(const FunctionInvocation& invocation)
{
    return business_.run(13, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction13(BusinessContext& business)
{
    return std::make_unique<Function13>(business);
}
