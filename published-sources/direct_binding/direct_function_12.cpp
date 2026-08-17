#include "direct_function_12.h"

DirectFunction12::DirectFunction12(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction12::execute(bool checked)
{
    result_ = business_.run(12, uiBias_, checked);
    ++executionCount_;
}
