#include "direct_function_108.h"

DirectFunction108::DirectFunction108(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction108::execute(bool checked)
{
    result_ = business_.run(108, uiBias_, checked);
    ++executionCount_;
}
