#pragma once

#include <QObject>

#include "business_context.h"

class DirectFunction141 final : public QObject
{
    Q_OBJECT

public:
    DirectFunction141(BusinessContext& business, int uiBias, QObject* parent = nullptr);
    int result() const noexcept { return result_; }
    int executionCount() const noexcept { return executionCount_; }

public slots:
    void execute(bool checked);

private:
    BusinessContext& business_;
    int uiBias_;
    int result_ = 0;
    int executionCount_ = 0;
};
