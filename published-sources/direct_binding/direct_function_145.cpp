#include "direct_function_145.h"

DirectFunction145::DirectFunction145(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction145::execute(bool checked)
{
    result_ = business_.run(145, uiBias_, checked);
    ++executionCount_;
}
