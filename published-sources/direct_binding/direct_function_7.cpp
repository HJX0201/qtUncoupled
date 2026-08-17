#include "direct_function_7.h"

DirectFunction7::DirectFunction7(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction7::execute(bool checked)
{
    result_ = business_.run(7, uiBias_, checked);
    ++executionCount_;
}
