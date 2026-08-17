#include "direct_function_35.h"

DirectFunction35::DirectFunction35(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction35::execute(bool checked)
{
    result_ = business_.run(35, uiBias_, checked);
    ++executionCount_;
}
