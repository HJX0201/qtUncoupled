#include "direct_function_118.h"

DirectFunction118::DirectFunction118(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction118::execute(bool checked)
{
    result_ = business_.run(118, uiBias_, checked);
    ++executionCount_;
}
