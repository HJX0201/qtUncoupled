#include "direct_function_4.h"

DirectFunction4::DirectFunction4(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction4::execute(bool checked)
{
    result_ = business_.run(4, uiBias_, checked);
    ++executionCount_;
}
