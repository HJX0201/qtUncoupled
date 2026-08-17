#include "direct_function_83.h"

DirectFunction83::DirectFunction83(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction83::execute(bool checked)
{
    result_ = business_.run(83, uiBias_, checked);
    ++executionCount_;
}
