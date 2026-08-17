#include "function_79.h"

#include <memory>

int Function79::execute(const FunctionInvocation& invocation)
{
    return business_.run(79, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction79(BusinessContext& business)
{
    return std::make_unique<Function79>(business);
}
