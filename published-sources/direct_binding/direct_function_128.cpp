#include "direct_function_128.h"

DirectFunction128::DirectFunction128(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction128::execute(bool checked)
{
    result_ = business_.run(128, uiBias_, checked);
    ++executionCount_;
}
