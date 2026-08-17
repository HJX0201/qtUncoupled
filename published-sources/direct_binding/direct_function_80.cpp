#include "direct_function_80.h"

DirectFunction80::DirectFunction80(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction80::execute(bool checked)
{
    result_ = business_.run(80, uiBias_, checked);
    ++executionCount_;
}
