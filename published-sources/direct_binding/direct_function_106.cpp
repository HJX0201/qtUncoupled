#include "direct_function_106.h"

DirectFunction106::DirectFunction106(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction106::execute(bool checked)
{
    result_ = business_.run(106, uiBias_, checked);
    ++executionCount_;
}
