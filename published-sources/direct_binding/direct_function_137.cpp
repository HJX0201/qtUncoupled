#include "direct_function_137.h"

DirectFunction137::DirectFunction137(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction137::execute(bool checked)
{
    result_ = business_.run(137, uiBias_, checked);
    ++executionCount_;
}
