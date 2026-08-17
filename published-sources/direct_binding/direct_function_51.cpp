#include "direct_function_51.h"

DirectFunction51::DirectFunction51(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction51::execute(bool checked)
{
    result_ = business_.run(51, uiBias_, checked);
    ++executionCount_;
}
