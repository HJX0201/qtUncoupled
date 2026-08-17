#include "direct_function_182.h"

DirectFunction182::DirectFunction182(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction182::execute(bool checked)
{
    result_ = business_.run(182, uiBias_, checked);
    ++executionCount_;
}
