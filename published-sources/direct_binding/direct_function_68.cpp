#include "direct_function_68.h"

DirectFunction68::DirectFunction68(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction68::execute(bool checked)
{
    result_ = business_.run(68, uiBias_, checked);
    ++executionCount_;
}
