#include "direct_function_73.h"

DirectFunction73::DirectFunction73(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction73::execute(bool checked)
{
    result_ = business_.run(73, uiBias_, checked);
    ++executionCount_;
}
