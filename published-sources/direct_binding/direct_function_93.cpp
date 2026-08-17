#include "direct_function_93.h"

DirectFunction93::DirectFunction93(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction93::execute(bool checked)
{
    result_ = business_.run(93, uiBias_, checked);
    ++executionCount_;
}
