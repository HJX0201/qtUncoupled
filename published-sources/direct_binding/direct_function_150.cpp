#include "direct_function_150.h"

DirectFunction150::DirectFunction150(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction150::execute(bool checked)
{
    result_ = business_.run(150, uiBias_, checked);
    ++executionCount_;
}
