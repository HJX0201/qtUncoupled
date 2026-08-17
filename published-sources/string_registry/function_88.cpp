#include "function_88.h"

#include <memory>

int Function88::execute(const FunctionInvocation& invocation)
{
    return business_.run(88, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction88(BusinessContext& business)
{
    return std::make_unique<Function88>(business);
}
