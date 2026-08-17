#include "direct_function_159.h"

DirectFunction159::DirectFunction159(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction159::execute(bool checked)
{
    result_ = business_.run(159, uiBias_, checked);
    ++executionCount_;
}
