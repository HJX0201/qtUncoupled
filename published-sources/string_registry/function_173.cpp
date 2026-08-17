#include "function_173.h"

#include <memory>

int Function173::execute(const FunctionInvocation& invocation)
{
    return business_.run(173, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction173(BusinessContext& business)
{
    return std::make_unique<Function173>(business);
}
