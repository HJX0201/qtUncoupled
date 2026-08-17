#include "direct_function_191.h"

DirectFunction191::DirectFunction191(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction191::execute(bool checked)
{
    result_ = business_.run(191, uiBias_, checked);
    ++executionCount_;
}
