#include "direct_function_162.h"

DirectFunction162::DirectFunction162(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction162::execute(bool checked)
{
    result_ = business_.run(162, uiBias_, checked);
    ++executionCount_;
}
