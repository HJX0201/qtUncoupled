#include "direct_function_113.h"

DirectFunction113::DirectFunction113(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction113::execute(bool checked)
{
    result_ = business_.run(113, uiBias_, checked);
    ++executionCount_;
}
