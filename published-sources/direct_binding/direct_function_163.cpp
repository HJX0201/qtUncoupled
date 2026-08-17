#include "direct_function_163.h"

DirectFunction163::DirectFunction163(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction163::execute(bool checked)
{
    result_ = business_.run(163, uiBias_, checked);
    ++executionCount_;
}
