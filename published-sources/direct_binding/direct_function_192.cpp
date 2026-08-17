#include "direct_function_192.h"

DirectFunction192::DirectFunction192(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction192::execute(bool checked)
{
    result_ = business_.run(192, uiBias_, checked);
    ++executionCount_;
}
