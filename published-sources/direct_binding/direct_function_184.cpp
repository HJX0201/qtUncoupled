#include "direct_function_184.h"

DirectFunction184::DirectFunction184(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction184::execute(bool checked)
{
    result_ = business_.run(184, uiBias_, checked);
    ++executionCount_;
}
