#include "direct_function_49.h"

DirectFunction49::DirectFunction49(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction49::execute(bool checked)
{
    result_ = business_.run(49, uiBias_, checked);
    ++executionCount_;
}
