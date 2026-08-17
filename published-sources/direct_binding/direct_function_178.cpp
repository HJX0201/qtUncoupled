#include "direct_function_178.h"

DirectFunction178::DirectFunction178(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction178::execute(bool checked)
{
    result_ = business_.run(178, uiBias_, checked);
    ++executionCount_;
}
