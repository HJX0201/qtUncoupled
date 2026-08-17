#include "direct_function_111.h"

DirectFunction111::DirectFunction111(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction111::execute(bool checked)
{
    result_ = business_.run(111, uiBias_, checked);
    ++executionCount_;
}
