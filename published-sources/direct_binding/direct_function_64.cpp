#include "direct_function_64.h"

DirectFunction64::DirectFunction64(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction64::execute(bool checked)
{
    result_ = business_.run(64, uiBias_, checked);
    ++executionCount_;
}
