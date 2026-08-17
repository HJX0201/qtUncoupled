#include "direct_function_133.h"

DirectFunction133::DirectFunction133(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction133::execute(bool checked)
{
    result_ = business_.run(133, uiBias_, checked);
    ++executionCount_;
}
