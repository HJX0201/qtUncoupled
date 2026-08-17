#include "direct_function_92.h"

DirectFunction92::DirectFunction92(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction92::execute(bool checked)
{
    result_ = business_.run(92, uiBias_, checked);
    ++executionCount_;
}
