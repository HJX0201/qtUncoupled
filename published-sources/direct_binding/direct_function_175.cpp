#include "direct_function_175.h"

DirectFunction175::DirectFunction175(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction175::execute(bool checked)
{
    result_ = business_.run(175, uiBias_, checked);
    ++executionCount_;
}
