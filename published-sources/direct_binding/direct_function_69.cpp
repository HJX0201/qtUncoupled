#include "direct_function_69.h"

DirectFunction69::DirectFunction69(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction69::execute(bool checked)
{
    result_ = business_.run(69, uiBias_, checked);
    ++executionCount_;
}
