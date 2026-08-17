#include "direct_function_36.h"

DirectFunction36::DirectFunction36(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction36::execute(bool checked)
{
    result_ = business_.run(36, uiBias_, checked);
    ++executionCount_;
}
