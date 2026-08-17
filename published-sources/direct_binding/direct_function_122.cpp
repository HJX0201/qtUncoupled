#include "direct_function_122.h"

DirectFunction122::DirectFunction122(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction122::execute(bool checked)
{
    result_ = business_.run(122, uiBias_, checked);
    ++executionCount_;
}
