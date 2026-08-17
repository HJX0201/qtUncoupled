#include "direct_function_161.h"

DirectFunction161::DirectFunction161(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction161::execute(bool checked)
{
    result_ = business_.run(161, uiBias_, checked);
    ++executionCount_;
}
