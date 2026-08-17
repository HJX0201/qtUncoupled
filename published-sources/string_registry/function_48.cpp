#include "function_48.h"

#include <memory>

int Function48::execute(const FunctionInvocation& invocation)
{
    return business_.run(48, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction48(BusinessContext& business)
{
    return std::make_unique<Function48>(business);
}
