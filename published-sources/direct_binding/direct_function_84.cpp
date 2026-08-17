#include "direct_function_84.h"

DirectFunction84::DirectFunction84(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction84::execute(bool checked)
{
    result_ = business_.run(84, uiBias_, checked);
    ++executionCount_;
}
