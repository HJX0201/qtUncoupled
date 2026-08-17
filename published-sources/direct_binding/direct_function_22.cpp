#include "direct_function_22.h"

DirectFunction22::DirectFunction22(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction22::execute(bool checked)
{
    result_ = business_.run(22, uiBias_, checked);
    ++executionCount_;
}
