#include "direct_function_143.h"

DirectFunction143::DirectFunction143(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction143::execute(bool checked)
{
    result_ = business_.run(143, uiBias_, checked);
    ++executionCount_;
}
