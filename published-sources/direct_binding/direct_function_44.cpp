#include "direct_function_44.h"

DirectFunction44::DirectFunction44(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction44::execute(bool checked)
{
    result_ = business_.run(44, uiBias_, checked);
    ++executionCount_;
}
