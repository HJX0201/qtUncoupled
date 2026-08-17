#include "direct_function_87.h"

DirectFunction87::DirectFunction87(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction87::execute(bool checked)
{
    result_ = business_.run(87, uiBias_, checked);
    ++executionCount_;
}
