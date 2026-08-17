#include "direct_function_67.h"

DirectFunction67::DirectFunction67(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction67::execute(bool checked)
{
    result_ = business_.run(67, uiBias_, checked);
    ++executionCount_;
}
