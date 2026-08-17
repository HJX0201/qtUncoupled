#include "direct_function_126.h"

DirectFunction126::DirectFunction126(BusinessContext& business, int uiBias, QObject* parent)
    : QObject(parent), business_(business), uiBias_(uiBias)
{
}

void DirectFunction126::execute(bool checked)
{
    result_ = business_.run(126, uiBias_, checked);
    ++executionCount_;
}
