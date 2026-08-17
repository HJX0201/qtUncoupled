#include "direct_function_33.h"

DirectFunction33::DirectFunction33(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction33::execute(bool checked)
{
    result_ = business_.run(33, uiBias_, checked);
    ++executionCount_;
}
