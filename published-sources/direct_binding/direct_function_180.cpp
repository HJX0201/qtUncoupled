#include "direct_function_180.h"

DirectFunction180::DirectFunction180(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction180::execute(bool checked)
{
    result_ = business_.run(180, uiBias_, checked);
    ++executionCount_;
}
