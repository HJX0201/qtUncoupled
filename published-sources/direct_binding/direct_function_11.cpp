#include "direct_function_11.h"

DirectFunction11::DirectFunction11(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction11::execute(bool checked)
{
    result_ = business_.run(11, uiBias_, checked);
    ++executionCount_;
}
