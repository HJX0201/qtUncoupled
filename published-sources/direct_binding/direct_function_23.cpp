#include "direct_function_23.h"

DirectFunction23::DirectFunction23(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction23::execute(bool checked)
{
    result_ = business_.run(23, uiBias_, checked);
    ++executionCount_;
}
