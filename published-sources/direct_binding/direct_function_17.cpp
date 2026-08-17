#include "direct_function_17.h"

DirectFunction17::DirectFunction17(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction17::execute(bool checked)
{
    result_ = business_.run(17, uiBias_, checked);
    ++executionCount_;
}
