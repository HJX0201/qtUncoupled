#include "function_77.h"

#include <memory>

int Function77::execute(const FunctionInvocation& invocation)
{
    return business_.run(77, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction77(BusinessContext& business)
{
    return std::make_unique<Function77>(business);
}
