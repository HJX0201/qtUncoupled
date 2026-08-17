#include "direct_function_121.h"

DirectFunction121::DirectFunction121(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction121::execute(bool checked)
{
    result_ = business_.run(121, uiBias_, checked);
    ++executionCount_;
}
