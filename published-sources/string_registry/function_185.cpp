#include "function_185.h"

#include <memory>

int Function185::execute(const FunctionInvocation& invocation)
{
    return business_.run(185, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction185(BusinessContext& business)
{
    return std::make_unique<Function185>(business);
}
