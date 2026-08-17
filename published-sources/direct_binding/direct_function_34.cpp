#include "direct_function_34.h"

DirectFunction34::DirectFunction34(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction34::execute(bool checked)
{
    result_ = business_.run(34, uiBias_, checked);
    ++executionCount_;
}
