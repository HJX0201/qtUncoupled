#include "direct_function_148.h"

DirectFunction148::DirectFunction148(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction148::execute(bool checked)
{
    result_ = business_.run(148, uiBias_, checked);
    ++executionCount_;
}
