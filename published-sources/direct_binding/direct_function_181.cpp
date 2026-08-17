#include "direct_function_181.h"

DirectFunction181::DirectFunction181(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction181::execute(bool checked)
{
    result_ = business_.run(181, uiBias_, checked);
    ++executionCount_;
}
