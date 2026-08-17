#include "direct_function_41.h"

DirectFunction41::DirectFunction41(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction41::execute(bool checked)
{
    result_ = business_.run(41, uiBias_, checked);
    ++executionCount_;
}
