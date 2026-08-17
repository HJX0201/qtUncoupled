#include "direct_function_123.h"

DirectFunction123::DirectFunction123(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction123::execute(bool checked)
{
    result_ = business_.run(123, uiBias_, checked);
    ++executionCount_;
}
