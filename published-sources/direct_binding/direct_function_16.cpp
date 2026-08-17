#include "direct_function_16.h"

DirectFunction16::DirectFunction16(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction16::execute(bool checked)
{
    result_ = business_.run(16, uiBias_, checked);
    ++executionCount_;
}
