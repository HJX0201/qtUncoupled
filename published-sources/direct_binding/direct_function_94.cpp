#include "direct_function_94.h"

DirectFunction94::DirectFunction94(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction94::execute(bool checked)
{
    result_ = business_.run(94, uiBias_, checked);
    ++executionCount_;
}
