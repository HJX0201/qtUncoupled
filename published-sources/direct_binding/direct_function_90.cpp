#include "direct_function_90.h"

DirectFunction90::DirectFunction90(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction90::execute(bool checked)
{
    result_ = business_.run(90, uiBias_, checked);
    ++executionCount_;
}
