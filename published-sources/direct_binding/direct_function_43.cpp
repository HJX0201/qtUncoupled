#include "direct_function_43.h"

DirectFunction43::DirectFunction43(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction43::execute(bool checked)
{
    result_ = business_.run(43, uiBias_, checked);
    ++executionCount_;
}
