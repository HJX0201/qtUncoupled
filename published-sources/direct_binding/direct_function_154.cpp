#include "direct_function_154.h"

DirectFunction154::DirectFunction154(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction154::execute(bool checked)
{
    result_ = business_.run(154, uiBias_, checked);
    ++executionCount_;
}
