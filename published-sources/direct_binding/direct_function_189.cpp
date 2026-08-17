#include "direct_function_189.h"

DirectFunction189::DirectFunction189(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction189::execute(bool checked)
{
    result_ = business_.run(189, uiBias_, checked);
    ++executionCount_;
}
