#include "direct_function_120.h"

DirectFunction120::DirectFunction120(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction120::execute(bool checked)
{
    result_ = business_.run(120, uiBias_, checked);
    ++executionCount_;
}
