#include "direct_function_177.h"

DirectFunction177::DirectFunction177(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction177::execute(bool checked)
{
    result_ = business_.run(177, uiBias_, checked);
    ++executionCount_;
}
