#include "direct_function_5.h"

DirectFunction5::DirectFunction5(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction5::execute(bool checked)
{
    result_ = business_.run(5, uiBias_, checked);
    ++executionCount_;
}
