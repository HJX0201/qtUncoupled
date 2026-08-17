#include "direct_function_155.h"

DirectFunction155::DirectFunction155(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction155::execute(bool checked)
{
    result_ = business_.run(155, uiBias_, checked);
    ++executionCount_;
}
