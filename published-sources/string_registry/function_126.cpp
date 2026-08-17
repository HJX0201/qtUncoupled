#include "function_126.h"

#include <memory>

int Function126::execute(const FunctionInvocation& invocation)
{
    return business_.run(126, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction126(BusinessContext& business)
{
    return std::make_unique<Function126>(business);
}
