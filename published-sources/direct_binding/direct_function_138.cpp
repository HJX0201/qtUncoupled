#include "direct_function_138.h"

DirectFunction138::DirectFunction138(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction138::execute(bool checked)
{
    result_ = business_.run(138, uiBias_, checked);
    ++executionCount_;
}
