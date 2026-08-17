#pragma once

#include "business_context.h"
#include "ifunction.h"

class Function188 final : public IFunction
{
public:
    explicit Function188(BusinessContext& business) noexcept
        : business_(business)
    {
    }

    int execute(const FunctionInvocation& invocation) override;

private:
    BusinessContext& business_;
};
