#include "direct_function_14.h"

DirectFunction14::DirectFunction14(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction14::execute(bool checked)
{
    result_ = business_.run(14, uiBias_, checked);
    ++executionCount_;
}
