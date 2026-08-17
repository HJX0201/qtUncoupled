#include "direct_function_91.h"

DirectFunction91::DirectFunction91(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction91::execute(bool checked)
{
    result_ = business_.run(91, uiBias_, checked);
    ++executionCount_;
}
