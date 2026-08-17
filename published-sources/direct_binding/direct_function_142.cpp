#include "direct_function_142.h"

DirectFunction142::DirectFunction142(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction142::execute(bool checked)
{
    result_ = business_.run(142, uiBias_, checked);
    ++executionCount_;
}
