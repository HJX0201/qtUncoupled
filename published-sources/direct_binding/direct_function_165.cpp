#include "direct_function_165.h"

DirectFunction165::DirectFunction165(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction165::execute(bool checked)
{
    result_ = business_.run(165, uiBias_, checked);
    ++executionCount_;
}
