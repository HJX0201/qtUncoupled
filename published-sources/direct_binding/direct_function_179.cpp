#include "direct_function_179.h"

DirectFunction179::DirectFunction179(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction179::execute(bool checked)
{
    result_ = business_.run(179, uiBias_, checked);
    ++executionCount_;
}
