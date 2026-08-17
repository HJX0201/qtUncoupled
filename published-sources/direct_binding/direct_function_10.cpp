#include "direct_function_10.h"

DirectFunction10::DirectFunction10(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction10::execute(bool checked)
{
    result_ = business_.run(10, uiBias_, checked);
    ++executionCount_;
}
