#include "direct_function_89.h"

DirectFunction89::DirectFunction89(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction89::execute(bool checked)
{
    result_ = business_.run(89, uiBias_, checked);
    ++executionCount_;
}
