#include "direct_function_183.h"

DirectFunction183::DirectFunction183(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction183::execute(bool checked)
{
    result_ = business_.run(183, uiBias_, checked);
    ++executionCount_;
}
