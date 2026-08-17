#include "function_27.h"

#include <memory>

int Function27::execute(const FunctionInvocation& invocation)
{
    return business_.run(27, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction27(BusinessContext& business)
{
    return std::make_unique<Function27>(business);
}
