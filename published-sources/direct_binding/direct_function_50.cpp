#include "direct_function_50.h"

DirectFunction50::DirectFunction50(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction50::execute(bool checked)
{
    result_ = business_.run(50, uiBias_, checked);
    ++executionCount_;
}
