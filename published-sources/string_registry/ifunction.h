#pragma once

#include "function_invocation.h"

class IFunction
{
public:
    virtual ~IFunction() = default;
    virtual int execute(const FunctionInvocation& invocation) = 0;
};
