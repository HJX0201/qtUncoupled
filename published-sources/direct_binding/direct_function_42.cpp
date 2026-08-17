#include "direct_function_42.h"

DirectFunction42::DirectFunction42(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction42::execute(bool checked)
{
    result_ = business_.run(42, uiBias_, checked);
    ++executionCount_;
}
