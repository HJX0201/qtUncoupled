#include "direct_function_147.h"

DirectFunction147::DirectFunction147(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction147::execute(bool checked)
{
    result_ = business_.run(147, uiBias_, checked);
    ++executionCount_;
}
