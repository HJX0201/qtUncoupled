#include "direct_function_66.h"

DirectFunction66::DirectFunction66(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction66::execute(bool checked)
{
    result_ = business_.run(66, uiBias_, checked);
    ++executionCount_;
}
