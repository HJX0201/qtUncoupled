#include "direct_function_140.h"

DirectFunction140::DirectFunction140(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction140::execute(bool checked)
{
    result_ = business_.run(140, uiBias_, checked);
    ++executionCount_;
}
