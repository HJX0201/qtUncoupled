#include "direct_function_70.h"

DirectFunction70::DirectFunction70(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction70::execute(bool checked)
{
    result_ = business_.run(70, uiBias_, checked);
    ++executionCount_;
}
