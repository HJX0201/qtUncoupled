#include "direct_function_103.h"

DirectFunction103::DirectFunction103(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction103::execute(bool checked)
{
    result_ = business_.run(103, uiBias_, checked);
    ++executionCount_;
}
