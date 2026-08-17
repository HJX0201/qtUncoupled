#include "direct_function_152.h"

DirectFunction152::DirectFunction152(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction152::execute(bool checked)
{
    result_ = business_.run(152, uiBias_, checked);
    ++executionCount_;
}
