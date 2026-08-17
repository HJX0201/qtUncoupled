#include "direct_function_124.h"

DirectFunction124::DirectFunction124(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction124::execute(bool checked)
{
    result_ = business_.run(124, uiBias_, checked);
    ++executionCount_;
}
