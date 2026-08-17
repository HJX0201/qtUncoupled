#include "direct_function_3.h"

DirectFunction3::DirectFunction3(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction3::execute(bool checked)
{
    result_ = business_.run(3, uiBias_, checked);
    ++executionCount_;
}
