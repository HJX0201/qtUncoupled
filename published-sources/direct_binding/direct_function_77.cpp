#include "direct_function_77.h"

DirectFunction77::DirectFunction77(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction77::execute(bool checked)
{
    result_ = business_.run(77, uiBias_, checked);
    ++executionCount_;
}
