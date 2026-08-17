#include "direct_function_160.h"

DirectFunction160::DirectFunction160(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction160::execute(bool checked)
{
    result_ = business_.run(160, uiBias_, checked);
    ++executionCount_;
}
