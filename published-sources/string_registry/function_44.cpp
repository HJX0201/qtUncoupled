#include "function_44.h"

#include <memory>

int Function44::execute(const FunctionInvocation& invocation)
{
    return business_.run(44, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction44(BusinessContext& business)
{
    return std::make_unique<Function44>(business);
}
