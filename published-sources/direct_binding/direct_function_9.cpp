#include "direct_function_9.h"

DirectFunction9::DirectFunction9(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction9::execute(bool checked)
{
    result_ = business_.run(9, uiBias_, checked);
    ++executionCount_;
}
