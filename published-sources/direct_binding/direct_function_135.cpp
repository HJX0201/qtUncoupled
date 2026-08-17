#include "direct_function_135.h"

DirectFunction135::DirectFunction135(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction135::execute(bool checked)
{
    result_ = business_.run(135, uiBias_, checked);
    ++executionCount_;
}
