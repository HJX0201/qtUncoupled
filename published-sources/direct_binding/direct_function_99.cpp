#include "direct_function_99.h"

DirectFunction99::DirectFunction99(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction99::execute(bool checked)
{
    result_ = business_.run(99, uiBias_, checked);
    ++executionCount_;
}
