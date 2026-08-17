#include "direct_function_0.h"

DirectFunction0::DirectFunction0(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction0::execute(bool checked)
{
    result_ = business_.run(0, uiBias_, checked);
    ++executionCount_;
}
