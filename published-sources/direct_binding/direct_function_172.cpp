#include "direct_function_172.h"

DirectFunction172::DirectFunction172(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction172::execute(bool checked)
{
    result_ = business_.run(172, uiBias_, checked);
    ++executionCount_;
}
