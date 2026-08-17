#include "direct_function_153.h"

DirectFunction153::DirectFunction153(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction153::execute(bool checked)
{
    result_ = business_.run(153, uiBias_, checked);
    ++executionCount_;
}
