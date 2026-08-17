#include "direct_function_54.h"

DirectFunction54::DirectFunction54(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction54::execute(bool checked)
{
    result_ = business_.run(54, uiBias_, checked);
    ++executionCount_;
}
