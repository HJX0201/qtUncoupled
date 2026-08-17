#include "direct_function_53.h"

DirectFunction53::DirectFunction53(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction53::execute(bool checked)
{
    result_ = business_.run(53, uiBias_, checked);
    ++executionCount_;
}
