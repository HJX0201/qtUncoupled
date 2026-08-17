#include "direct_function_59.h"

DirectFunction59::DirectFunction59(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction59::execute(bool checked)
{
    result_ = business_.run(59, uiBias_, checked);
    ++executionCount_;
}
