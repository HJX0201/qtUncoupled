#include "direct_function_176.h"

DirectFunction176::DirectFunction176(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction176::execute(bool checked)
{
    result_ = business_.run(176, uiBias_, checked);
    ++executionCount_;
}
