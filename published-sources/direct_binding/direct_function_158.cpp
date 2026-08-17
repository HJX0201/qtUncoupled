#include "direct_function_158.h"

DirectFunction158::DirectFunction158(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction158::execute(bool checked)
{
    result_ = business_.run(158, uiBias_, checked);
    ++executionCount_;
}
