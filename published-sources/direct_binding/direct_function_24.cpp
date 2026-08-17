#include "direct_function_24.h"

DirectFunction24::DirectFunction24(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction24::execute(bool checked)
{
    result_ = business_.run(24, uiBias_, checked);
    ++executionCount_;
}
