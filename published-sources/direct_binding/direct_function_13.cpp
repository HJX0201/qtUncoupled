#include "direct_function_13.h"

DirectFunction13::DirectFunction13(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction13::execute(bool checked)
{
    result_ = business_.run(13, uiBias_, checked);
    ++executionCount_;
}
