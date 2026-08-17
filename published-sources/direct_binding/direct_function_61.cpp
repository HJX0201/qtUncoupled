#include "direct_function_61.h"

DirectFunction61::DirectFunction61(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction61::execute(bool checked)
{
    result_ = business_.run(61, uiBias_, checked);
    ++executionCount_;
}
