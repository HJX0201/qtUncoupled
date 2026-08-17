#include "direct_function_78.h"

DirectFunction78::DirectFunction78(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction78::execute(bool checked)
{
    result_ = business_.run(78, uiBias_, checked);
    ++executionCount_;
}
