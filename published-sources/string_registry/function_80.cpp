#include "function_80.h"

#include <memory>

int Function80::execute(const FunctionInvocation& invocation)
{
    return business_.run(80, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction80(BusinessContext& business)
{
    return std::make_unique<Function80>(business);
}
