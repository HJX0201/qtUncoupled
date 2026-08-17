#include "direct_function_125.h"

DirectFunction125::DirectFunction125(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction125::execute(bool checked)
{
    result_ = business_.run(125, uiBias_, checked);
    ++executionCount_;
}
