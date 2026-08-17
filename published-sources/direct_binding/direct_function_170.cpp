#include "direct_function_170.h"

DirectFunction170::DirectFunction170(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction170::execute(bool checked)
{
    result_ = business_.run(170, uiBias_, checked);
    ++executionCount_;
}
