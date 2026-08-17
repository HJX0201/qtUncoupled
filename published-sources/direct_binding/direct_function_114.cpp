#include "direct_function_114.h"

DirectFunction114::DirectFunction114(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction114::execute(bool checked)
{
    result_ = business_.run(114, uiBias_, checked);
    ++executionCount_;
}
