#include "function_160.h"

#include <memory>

int Function160::execute(const FunctionInvocation& invocation)
{
    return business_.run(160, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction160(BusinessContext& business)
{
    return std::make_unique<Function160>(business);
}
