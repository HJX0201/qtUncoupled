#include "direct_function_25.h"

DirectFunction25::DirectFunction25(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction25::execute(bool checked)
{
    result_ = business_.run(25, uiBias_, checked);
    ++executionCount_;
}
