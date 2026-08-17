#include "direct_function_95.h"

DirectFunction95::DirectFunction95(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction95::execute(bool checked)
{
    result_ = business_.run(95, uiBias_, checked);
    ++executionCount_;
}
