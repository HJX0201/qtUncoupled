#include "direct_function_134.h"

DirectFunction134::DirectFunction134(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction134::execute(bool checked)
{
    result_ = business_.run(134, uiBias_, checked);
    ++executionCount_;
}
