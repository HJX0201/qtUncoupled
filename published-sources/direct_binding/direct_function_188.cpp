#include "direct_function_188.h"

DirectFunction188::DirectFunction188(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction188::execute(bool checked)
{
    result_ = business_.run(188, uiBias_, checked);
    ++executionCount_;
}
