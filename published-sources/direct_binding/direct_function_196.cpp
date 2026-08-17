#include "direct_function_196.h"

DirectFunction196::DirectFunction196(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction196::execute(bool checked)
{
    result_ = business_.run(196, uiBias_, checked);
    ++executionCount_;
}
