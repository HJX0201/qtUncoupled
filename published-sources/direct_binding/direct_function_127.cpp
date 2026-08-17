#include "direct_function_127.h"

DirectFunction127::DirectFunction127(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction127::execute(bool checked)
{
    result_ = business_.run(127, uiBias_, checked);
    ++executionCount_;
}
