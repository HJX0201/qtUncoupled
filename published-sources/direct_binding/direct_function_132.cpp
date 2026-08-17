#include "direct_function_132.h"

DirectFunction132::DirectFunction132(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction132::execute(bool checked)
{
    result_ = business_.run(132, uiBias_, checked);
    ++executionCount_;
}
