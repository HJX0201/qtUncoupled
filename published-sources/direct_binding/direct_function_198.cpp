#include "direct_function_198.h"

DirectFunction198::DirectFunction198(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction198::execute(bool checked)
{
    result_ = business_.run(198, uiBias_, checked);
    ++executionCount_;
}
