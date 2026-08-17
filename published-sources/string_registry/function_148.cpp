#include "function_148.h"

#include <memory>

int Function148::execute(const FunctionInvocation& invocation)
{
    return business_.run(148, invocation.uiBias, invocation.checked);
}

std::unique_ptr<IFunction> makeFunction148(BusinessContext& business)
{
    return std::make_unique<Function148>(business);
}
