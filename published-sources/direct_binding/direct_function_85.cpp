#include "direct_function_85.h"

DirectFunction85::DirectFunction85(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction85::execute(bool checked)
{
    result_ = business_.run(85, uiBias_, checked);
    ++executionCount_;
}
