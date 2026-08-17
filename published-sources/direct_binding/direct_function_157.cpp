#include "direct_function_157.h"

DirectFunction157::DirectFunction157(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction157::execute(bool checked)
{
    result_ = business_.run(157, uiBias_, checked);
    ++executionCount_;
}
