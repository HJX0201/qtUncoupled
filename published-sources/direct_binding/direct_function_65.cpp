#include "direct_function_65.h"

DirectFunction65::DirectFunction65(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction65::execute(bool checked)
{
    result_ = business_.run(65, uiBias_, checked);
    ++executionCount_;
}
