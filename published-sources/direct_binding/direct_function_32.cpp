#include "direct_function_32.h"

DirectFunction32::DirectFunction32(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction32::execute(bool checked)
{
    result_ = business_.run(32, uiBias_, checked);
    ++executionCount_;
}
