#include "direct_function_71.h"

DirectFunction71::DirectFunction71(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction71::execute(bool checked)
{
    result_ = business_.run(71, uiBias_, checked);
    ++executionCount_;
}
