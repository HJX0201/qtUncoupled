#include "direct_function_75.h"

DirectFunction75::DirectFunction75(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction75::execute(bool checked)
{
    result_ = business_.run(75, uiBias_, checked);
    ++executionCount_;
}
