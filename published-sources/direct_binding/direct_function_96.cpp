#include "direct_function_96.h"

DirectFunction96::DirectFunction96(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction96::execute(bool checked)
{
    result_ = business_.run(96, uiBias_, checked);
    ++executionCount_;
}
