#include "direct_function_98.h"

DirectFunction98::DirectFunction98(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction98::execute(bool checked)
{
    result_ = business_.run(98, uiBias_, checked);
    ++executionCount_;
}
