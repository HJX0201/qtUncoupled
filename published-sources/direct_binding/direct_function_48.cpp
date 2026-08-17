#include "direct_function_48.h"

DirectFunction48::DirectFunction48(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction48::execute(bool checked)
{
    result_ = business_.run(48, uiBias_, checked);
    ++executionCount_;
}
