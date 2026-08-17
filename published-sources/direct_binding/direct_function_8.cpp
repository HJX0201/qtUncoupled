#include "direct_function_8.h"

DirectFunction8::DirectFunction8(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction8::execute(bool checked)
{
    result_ = business_.run(8, uiBias_, checked);
    ++executionCount_;
}
