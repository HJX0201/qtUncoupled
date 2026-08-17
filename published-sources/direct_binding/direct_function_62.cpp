#include "direct_function_62.h"

DirectFunction62::DirectFunction62(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction62::execute(bool checked)
{
    result_ = business_.run(62, uiBias_, checked);
    ++executionCount_;
}
