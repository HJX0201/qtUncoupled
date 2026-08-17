#include "function_136.h"

#include <memory>

int Function136::execute(const FunctionInvocation& invocation)
{
    return business_.run(136, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction136(BusinessContext& business)
{
    return std::make_unique<Function136>(business);
}
