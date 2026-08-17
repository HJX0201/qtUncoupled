#include "direct_function_194.h"

DirectFunction194::DirectFunction194(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction194::execute(bool checked)
{
    result_ = business_.run(194, uiBias_, checked);
    ++executionCount_;
}
