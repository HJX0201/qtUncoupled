#include "function_167.h"

#include <memory>

int Function167::execute(const FunctionInvocation& invocation)
{
    return business_.run(167, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction167(BusinessContext& business)
{
    return std::make_unique<Function167>(business);
}
