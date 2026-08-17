#include "direct_function_82.h"

DirectFunction82::DirectFunction82(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction82::execute(bool checked)
{
    result_ = business_.run(82, uiBias_, checked);
    ++executionCount_;
}
