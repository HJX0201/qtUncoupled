#include "direct_function_26.h"

DirectFunction26::DirectFunction26(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction26::execute(bool checked)
{
    result_ = business_.run(26, uiBias_, checked);
    ++executionCount_;
}
