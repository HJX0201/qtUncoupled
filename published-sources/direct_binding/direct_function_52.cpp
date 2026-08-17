#include "direct_function_52.h"

DirectFunction52::DirectFunction52(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction52::execute(bool checked)
{
    result_ = business_.run(52, uiBias_, checked);
    ++executionCount_;
}
