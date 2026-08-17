#include "direct_function_19.h"

DirectFunction19::DirectFunction19(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction19::execute(bool checked)
{
    result_ = business_.run(19, uiBias_, checked);
    ++executionCount_;
}
