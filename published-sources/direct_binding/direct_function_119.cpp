#include "direct_function_119.h"

DirectFunction119::DirectFunction119(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction119::execute(bool checked)
{
    result_ = business_.run(119, uiBias_, checked);
    ++executionCount_;
}
