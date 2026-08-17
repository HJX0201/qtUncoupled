#include "direct_function_74.h"

DirectFunction74::DirectFunction74(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction74::execute(bool checked)
{
    result_ = business_.run(74, uiBias_, checked);
    ++executionCount_;
}
