#include "direct_function_105.h"

DirectFunction105::DirectFunction105(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction105::execute(bool checked)
{
    result_ = business_.run(105, uiBias_, checked);
    ++executionCount_;
}
