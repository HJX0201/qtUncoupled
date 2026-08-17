#include "direct_function_115.h"

DirectFunction115::DirectFunction115(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction115::execute(bool checked)
{
    result_ = business_.run(115, uiBias_, checked);
    ++executionCount_;
}
