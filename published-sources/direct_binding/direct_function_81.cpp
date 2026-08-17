#include "direct_function_81.h"

DirectFunction81::DirectFunction81(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction81::execute(bool checked)
{
    result_ = business_.run(81, uiBias_, checked);
    ++executionCount_;
}
