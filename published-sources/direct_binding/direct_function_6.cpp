#include "direct_function_6.h"

DirectFunction6::DirectFunction6(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction6::execute(bool checked)
{
    result_ = business_.run(6, uiBias_, checked);
    ++executionCount_;
}
