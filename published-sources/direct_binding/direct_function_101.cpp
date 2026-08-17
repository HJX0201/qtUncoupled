#include "direct_function_101.h"

DirectFunction101::DirectFunction101(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction101::execute(bool checked)
{
    result_ = business_.run(101, uiBias_, checked);
    ++executionCount_;
}
