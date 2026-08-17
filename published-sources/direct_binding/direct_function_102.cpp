#include "direct_function_102.h"

DirectFunction102::DirectFunction102(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction102::execute(bool checked)
{
    result_ = business_.run(102, uiBias_, checked);
    ++executionCount_;
}
