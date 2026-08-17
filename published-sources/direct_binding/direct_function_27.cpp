#include "direct_function_27.h"

DirectFunction27::DirectFunction27(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction27::execute(bool checked)
{
    result_ = business_.run(27, uiBias_, checked);
    ++executionCount_;
}
