#pragma once

#include "business_context.h"
#include "ifunction.h"

class Function108 final : public IFunction
{
public:
    explicit Function108(BusinessContext& business) noexcept
        : business_(business)
    {
    }

    int execute(const FunctionInvocation& invocation) override;

private:
    BusinessContext& business_;
};
