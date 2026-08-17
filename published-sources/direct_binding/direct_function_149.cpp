#include "direct_function_149.h"

DirectFunction149::DirectFunction149(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction149::execute(bool checked)
{
    result_ = business_.run(149, uiBias_, checked);
    ++executionCount_;
}
