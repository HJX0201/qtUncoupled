#include "direct_function_164.h"

DirectFunction164::DirectFunction164(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction164::execute(bool checked)
{
    result_ = business_.run(164, uiBias_, checked);
    ++executionCount_;
}
