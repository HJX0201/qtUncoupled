#include "direct_function_185.h"

DirectFunction185::DirectFunction185(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction185::execute(bool checked)
{
    result_ = business_.run(185, uiBias_, checked);
    ++executionCount_;
}
