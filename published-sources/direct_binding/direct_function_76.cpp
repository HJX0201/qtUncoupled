#include "direct_function_76.h"

DirectFunction76::DirectFunction76(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction76::execute(bool checked)
{
    result_ = business_.run(76, uiBias_, checked);
    ++executionCount_;
}
