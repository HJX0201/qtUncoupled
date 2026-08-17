#include "direct_function_40.h"

DirectFunction40::DirectFunction40(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction40::execute(bool checked)
{
    result_ = business_.run(40, uiBias_, checked);
    ++executionCount_;
}
