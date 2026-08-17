#include "direct_function_57.h"

DirectFunction57::DirectFunction57(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction57::execute(bool checked)
{
    result_ = business_.run(57, uiBias_, checked);
    ++executionCount_;
}
