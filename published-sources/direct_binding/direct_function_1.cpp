#include "direct_function_1.h"

DirectFunction1::DirectFunction1(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction1::execute(bool checked)
{
    result_ = business_.run(1, uiBias_, checked);
    ++executionCount_;
}
