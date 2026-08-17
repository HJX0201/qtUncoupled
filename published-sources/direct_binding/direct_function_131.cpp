#include "direct_function_131.h"

DirectFunction131::DirectFunction131(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction131::execute(bool checked)
{
    result_ = business_.run(131, uiBias_, checked);
    ++executionCount_;
}
