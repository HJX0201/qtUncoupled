#include "direct_function_55.h"

DirectFunction55::DirectFunction55(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction55::execute(bool checked)
{
    result_ = business_.run(55, uiBias_, checked);
    ++executionCount_;
}
