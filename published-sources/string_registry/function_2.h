#pragma once

#include "business_context.h"
#include "ifunction.h"

class Function2 final : public IFunction
{
public:
    explicit Function2(BusinessContext& business) noexcept
        : business_(business)
    {
    }

    int execute(const FunctionInvocation& invocation) override;

private:
    BusinessContext& business_;
};
