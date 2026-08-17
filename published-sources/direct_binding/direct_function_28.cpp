#include "direct_function_28.h"

DirectFunction28::DirectFunction28(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction28::execute(bool checked)
{
    result_ = business_.run(28, uiBias_, checked);
    ++executionCount_;
}
