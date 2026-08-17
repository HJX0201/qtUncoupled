#include "direct_function_117.h"

DirectFunction117::DirectFunction117(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction117::execute(bool checked)
{
    result_ = business_.run(117, uiBias_, checked);
    ++executionCount_;
}
