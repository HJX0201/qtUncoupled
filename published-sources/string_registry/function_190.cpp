#include "function_190.h"

#include <memory>

int Function190::execute(const FunctionInvocation& invocation)
{
    return business_.run(190, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction190(BusinessContext& business)
{
    return std::make_unique<Function190>(business);
}
