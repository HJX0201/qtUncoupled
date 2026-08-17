#include "direct_function_58.h"

DirectFunction58::DirectFunction58(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction58::execute(bool checked)
{
    result_ = business_.run(58, uiBias_, checked);
    ++executionCount_;
}
