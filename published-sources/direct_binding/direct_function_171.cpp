#include "direct_function_171.h"

DirectFunction171::DirectFunction171(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction171::execute(bool checked)
{
    result_ = business_.run(171, uiBias_, checked);
    ++executionCount_;
}
