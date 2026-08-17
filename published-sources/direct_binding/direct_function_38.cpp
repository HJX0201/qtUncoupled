#include "direct_function_38.h"

DirectFunction38::DirectFunction38(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction38::execute(bool checked)
{
    result_ = business_.run(38, uiBias_, checked);
    ++executionCount_;
}
