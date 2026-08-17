#include "direct_function_136.h"

DirectFunction136::DirectFunction136(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction136::execute(bool checked)
{
    result_ = business_.run(136, uiBias_, checked);
    ++executionCount_;
}
