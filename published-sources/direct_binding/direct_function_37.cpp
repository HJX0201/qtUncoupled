#include "direct_function_37.h"

DirectFunction37::DirectFunction37(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction37::execute(bool checked)
{
    result_ = business_.run(37, uiBias_, checked);
    ++executionCount_;
}
