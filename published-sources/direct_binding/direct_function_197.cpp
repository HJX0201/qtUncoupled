#include "direct_function_197.h"

DirectFunction197::DirectFunction197(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction197::execute(bool checked)
{
    result_ = business_.run(197, uiBias_, checked);
    ++executionCount_;
}
