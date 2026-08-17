#include "function_195.h"

#include <memory>

int Function195::execute(const FunctionInvocation& invocation)
{
    return business_.run(195, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction195(BusinessContext& business)
{
    return std::make_unique<Function195>(business);
}
