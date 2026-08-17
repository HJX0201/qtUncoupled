#include "direct_function_47.h"

DirectFunction47::DirectFunction47(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction47::execute(bool checked)
{
    result_ = business_.run(47, uiBias_, checked);
    ++executionCount_;
}
