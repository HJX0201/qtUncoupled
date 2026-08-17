#include "direct_function_72.h"

DirectFunction72::DirectFunction72(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction72::execute(bool checked)
{
    result_ = business_.run(72, uiBias_, checked);
    ++executionCount_;
}
