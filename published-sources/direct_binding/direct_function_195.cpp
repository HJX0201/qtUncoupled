#include "direct_function_195.h"

DirectFunction195::DirectFunction195(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction195::execute(bool checked)
{
    result_ = business_.run(195, uiBias_, checked);
    ++executionCount_;
}
