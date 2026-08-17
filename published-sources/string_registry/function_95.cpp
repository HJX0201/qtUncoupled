#include "function_95.h"

#include <memory>

int Function95::execute(const FunctionInvocation& invocation)
{
    return business_.run(95, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction95(BusinessContext& business)
{
    return std::make_unique<Function95>(business);
}
