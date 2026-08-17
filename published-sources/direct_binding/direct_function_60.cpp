#include "direct_function_60.h"

DirectFunction60::DirectFunction60(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction60::execute(bool checked)
{
    result_ = business_.run(60, uiBias_, checked);
    ++executionCount_;
}
