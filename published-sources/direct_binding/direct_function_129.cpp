#include "direct_function_129.h"

DirectFunction129::DirectFunction129(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction129::execute(bool checked)
{
    result_ = business_.run(129, uiBias_, checked);
    ++executionCount_;
}
