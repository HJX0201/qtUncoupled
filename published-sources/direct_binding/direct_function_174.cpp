#include "direct_function_174.h"

DirectFunction174::DirectFunction174(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction174::execute(bool checked)
{
    result_ = business_.run(174, uiBias_, checked);
    ++executionCount_;
}
