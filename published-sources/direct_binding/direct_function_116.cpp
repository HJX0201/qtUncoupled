#include "direct_function_116.h"

DirectFunction116::DirectFunction116(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction116::execute(bool checked)
{
    result_ = business_.run(116, uiBias_, checked);
    ++executionCount_;
}
