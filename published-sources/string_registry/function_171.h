#pragma once

#include "business_context.h"
#include "ifunction.h"

class Function171 final : public IFunction
{
public:
    explicit Function171(BusinessContext& business) noexcept
        : business_(business)
    {
    }

    int execute(const FunctionInvocation& invocation) override;

private:
    BusinessContext& business_;
};
