#include "direct_function_151.h"

DirectFunction151::DirectFunction151(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction151::execute(bool checked)
{
    result_ = business_.run(151, uiBias_, checked);
    ++executionCount_;
}
