#include "function_196.h"

#include <memory>

int Function196::execute(const FunctionInvocation& invocation)
{
    return business_.run(196, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction196(BusinessContext& business)
{
    return std::make_unique<Function196>(business);
}
