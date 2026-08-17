#include "direct_function_97.h"

DirectFunction97::DirectFunction97(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction97::execute(bool checked)
{
    result_ = business_.run(97, uiBias_, checked);
    ++executionCount_;
}
