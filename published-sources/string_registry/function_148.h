#pragma once

#include "business_context.h"
#include "ifunction.h"

class Function148 final : public IFunction
{
public:
    explicit Function148(BusinessContext& business) noexcept
        : business_(business)
    {
    }

    int execute(const FunctionInvocation& invocation) override;

private:
    BusinessContext& business_;
};
