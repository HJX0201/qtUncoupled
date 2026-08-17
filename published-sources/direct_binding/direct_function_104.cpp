#include "direct_function_104.h"

DirectFunction104::DirectFunction104(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction104::execute(bool checked)
{
    result_ = business_.run(104, uiBias_, checked);
    ++executionCount_;
}
