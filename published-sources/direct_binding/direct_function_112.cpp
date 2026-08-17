#include "direct_function_112.h"

DirectFunction112::DirectFunction112(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction112::execute(bool checked)
{
    result_ = business_.run(112, uiBias_, checked);
    ++executionCount_;
}
