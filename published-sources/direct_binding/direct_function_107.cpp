#include "direct_function_107.h"

DirectFunction107::DirectFunction107(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction107::execute(bool checked)
{
    result_ = business_.run(107, uiBias_, checked);
    ++executionCount_;
}
