#include "direct_function_130.h"

DirectFunction130::DirectFunction130(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction130::execute(bool checked)
{
    result_ = business_.run(130, uiBias_, checked);
    ++executionCount_;
}
