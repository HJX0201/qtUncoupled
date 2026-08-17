#include "direct_function_169.h"

DirectFunction169::DirectFunction169(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction169::execute(bool checked)
{
    result_ = business_.run(169, uiBias_, checked);
    ++executionCount_;
}
