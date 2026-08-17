#include "function_112.h"

#include <memory>

int Function112::execute(const FunctionInvocation& invocation)
{
    return business_.run(112, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction112(BusinessContext& business)
{
    return std::make_unique<Function112>(business);
}
