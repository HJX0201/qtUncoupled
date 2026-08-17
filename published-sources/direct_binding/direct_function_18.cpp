#include "direct_function_18.h"

DirectFunction18::DirectFunction18(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction18::execute(bool checked)
{
    result_ = business_.run(18, uiBias_, checked);
    ++executionCount_;
}
