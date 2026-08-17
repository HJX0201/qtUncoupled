#include "direct_function_193.h"

DirectFunction193::DirectFunction193(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction193::execute(bool checked)
{
    result_ = business_.run(193, uiBias_, checked);
    ++executionCount_;
}
