#include "direct_function_167.h"

DirectFunction167::DirectFunction167(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction167::execute(bool checked)
{
    result_ = business_.run(167, uiBias_, checked);
    ++executionCount_;
}
