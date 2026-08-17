#include "function_189.h"

#include <memory>

int Function189::execute(const FunctionInvocation& invocation)
{
    return business_.run(189, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction189(BusinessContext& business)
{
    return std::make_unique<Function189>(business);
}
