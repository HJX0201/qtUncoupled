#include "direct_function_20.h"

DirectFunction20::DirectFunction20(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction20::execute(bool checked)
{
    result_ = business_.run(20, uiBias_, checked);
    ++executionCount_;
}
