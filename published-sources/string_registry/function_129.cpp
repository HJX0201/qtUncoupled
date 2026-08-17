#include "function_129.h"

#include <memory>

int Function129::execute(const FunctionInvocation& invocation)
{
    return business_.run(129, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction129(BusinessContext& business)
{
    return std::make_unique<Function129>(business);
}
