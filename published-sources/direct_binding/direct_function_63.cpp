#include "direct_function_63.h"

DirectFunction63::DirectFunction63(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction63::execute(bool checked)
{
    result_ = business_.run(63, uiBias_, checked);
    ++executionCount_;
}
