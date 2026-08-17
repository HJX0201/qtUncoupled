#include "direct_function_187.h"

DirectFunction187::DirectFunction187(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction187::execute(bool checked)
{
    result_ = business_.run(187, uiBias_, checked);
    ++executionCount_;
}
