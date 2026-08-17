#include "direct_function_30.h"

DirectFunction30::DirectFunction30(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction30::execute(bool checked)
{
    result_ = business_.run(30, uiBias_, checked);
    ++executionCount_;
}
