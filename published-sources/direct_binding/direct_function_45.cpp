#include "direct_function_45.h"

DirectFunction45::DirectFunction45(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction45::execute(bool checked)
{
    result_ = business_.run(45, uiBias_, checked);
    ++executionCount_;
}
