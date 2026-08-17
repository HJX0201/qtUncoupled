#include "direct_function_139.h"

DirectFunction139::DirectFunction139(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction139::execute(bool checked)
{
    result_ = business_.run(139, uiBias_, checked);
    ++executionCount_;
}
