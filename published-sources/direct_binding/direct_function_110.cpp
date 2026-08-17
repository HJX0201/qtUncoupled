#include "direct_function_110.h"

DirectFunction110::DirectFunction110(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction110::execute(bool checked)
{
    result_ = business_.run(110, uiBias_, checked);
    ++executionCount_;
}
