#include "direct_function_79.h"

DirectFunction79::DirectFunction79(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction79::execute(bool checked)
{
    result_ = business_.run(79, uiBias_, checked);
    ++executionCount_;
}
