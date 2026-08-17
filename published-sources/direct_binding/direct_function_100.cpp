#include "direct_function_100.h"

DirectFunction100::DirectFunction100(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction100::execute(bool checked)
{
    result_ = business_.run(100, uiBias_, checked);
    ++executionCount_;
}
