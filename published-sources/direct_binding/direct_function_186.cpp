#include "direct_function_186.h"

DirectFunction186::DirectFunction186(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction186::execute(bool checked)
{
    result_ = business_.run(186, uiBias_, checked);
    ++executionCount_;
}
