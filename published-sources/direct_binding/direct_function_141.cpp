#include "direct_function_141.h"

DirectFunction141::DirectFunction141(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction141::execute(bool checked)
{
    result_ = business_.run(141, uiBias_, checked);
    ++executionCount_;
}
