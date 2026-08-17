#include "direct_function_173.h"

DirectFunction173::DirectFunction173(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction173::execute(bool checked)
{
    result_ = business_.run(173, uiBias_, checked);
    ++executionCount_;
}
