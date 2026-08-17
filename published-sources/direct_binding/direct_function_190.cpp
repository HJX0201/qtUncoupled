#include "direct_function_190.h"

DirectFunction190::DirectFunction190(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction190::execute(bool checked)
{
    result_ = business_.run(190, uiBias_, checked);
    ++executionCount_;
}
