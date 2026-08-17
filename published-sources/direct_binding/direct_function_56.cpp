#include "direct_function_56.h"

DirectFunction56::DirectFunction56(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction56::execute(bool checked)
{
    result_ = business_.run(56, uiBias_, checked);
    ++executionCount_;
}
