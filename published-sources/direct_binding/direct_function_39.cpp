#include "direct_function_39.h"

DirectFunction39::DirectFunction39(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction39::execute(bool checked)
{
    result_ = business_.run(39, uiBias_, checked);
    ++executionCount_;
}
