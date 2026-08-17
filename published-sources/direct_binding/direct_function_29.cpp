#include "direct_function_29.h"

DirectFunction29::DirectFunction29(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction29::execute(bool checked)
{
    result_ = business_.run(29, uiBias_, checked);
    ++executionCount_;
}
