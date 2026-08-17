#include "direct_function_146.h"

DirectFunction146::DirectFunction146(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction146::execute(bool checked)
{
    result_ = business_.run(146, uiBias_, checked);
    ++executionCount_;
}
