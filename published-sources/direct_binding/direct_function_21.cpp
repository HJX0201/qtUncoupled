#include "direct_function_21.h"

DirectFunction21::DirectFunction21(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction21::execute(bool checked)
{
    result_ = business_.run(21, uiBias_, checked);
    ++executionCount_;
}
