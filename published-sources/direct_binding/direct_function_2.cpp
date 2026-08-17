#include "direct_function_2.h"

DirectFunction2::DirectFunction2(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction2::execute(bool checked)
{
    result_ = business_.run(2, uiBias_, checked);
    ++executionCount_;
}
