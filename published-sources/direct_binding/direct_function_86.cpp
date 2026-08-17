#include "direct_function_86.h"

DirectFunction86::DirectFunction86(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction86::execute(bool checked)
{
    result_ = business_.run(86, uiBias_, checked);
    ++executionCount_;
}
