#include "direct_function_168.h"

DirectFunction168::DirectFunction168(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction168::execute(bool checked)
{
    result_ = business_.run(168, uiBias_, checked);
    ++executionCount_;
}
