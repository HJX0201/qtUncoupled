#include "direct_function_31.h"

DirectFunction31::DirectFunction31(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction31::execute(bool checked)
{
    result_ = business_.run(31, uiBias_, checked);
    ++executionCount_;
}
