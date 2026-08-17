#include "direct_function_156.h"

DirectFunction156::DirectFunction156(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction156::execute(bool checked)
{
    result_ = business_.run(156, uiBias_, checked);
    ++executionCount_;
}
