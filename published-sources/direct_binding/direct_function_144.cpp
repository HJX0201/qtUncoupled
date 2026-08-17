#include "direct_function_144.h"

DirectFunction144::DirectFunction144(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction144::execute(bool checked)
{
    result_ = business_.run(144, uiBias_, checked);
    ++executionCount_;
}
