#include "direct_function_199.h"

DirectFunction199::DirectFunction199(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction199::execute(bool checked)
{
    result_ = business_.run(199, uiBias_, checked);
    ++executionCount_;
}
