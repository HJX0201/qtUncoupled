#include "direct_function_109.h"

DirectFunction109::DirectFunction109(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction109::execute(bool checked)
{
    result_ = business_.run(109, uiBias_, checked);
    ++executionCount_;
}
