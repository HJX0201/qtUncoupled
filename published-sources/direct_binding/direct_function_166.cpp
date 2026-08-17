#include "direct_function_166.h"

DirectFunction166::DirectFunction166(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction166::execute(bool checked)
{
    result_ = business_.run(166, uiBias_, checked);
    ++executionCount_;
}
