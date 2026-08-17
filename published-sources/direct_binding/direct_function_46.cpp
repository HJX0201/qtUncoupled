#include "direct_function_46.h"

DirectFunction46::DirectFunction46(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction46::execute(bool checked)
{
    result_ = business_.run(46, uiBias_, checked);
    ++executionCount_;
}
