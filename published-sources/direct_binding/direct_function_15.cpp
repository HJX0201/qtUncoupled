#include "direct_function_15.h"

DirectFunction15::DirectFunction15(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction15::execute(bool checked)
{
    result_ = business_.run(15, uiBias_, checked);
    ++executionCount_;
}
