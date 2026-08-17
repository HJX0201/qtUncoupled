#include "action_router.h"

#include <QAction>
#include <QString>

#include "function_registry.h"
#include "ui_context.h"

ActionRouter::ActionRouter(
    FunctionRegistry& registry,
    const UiContext& ui,
    RouterState& state) noexcept
    : registry_(registry), ui_(ui), state_(state)
{
}

void ActionRouter::dispatch(QAction* action)
{
    if (!action) {
        ++state_.failedDispatchCount;
        return;
    }

    state_.lastFunctionId = action->data().toString().toStdString();
    const FunctionInvocation invocation{ui_.bias(), action->isChecked()};
    const auto result = registry_.execute(state_.lastFunctionId, invocation);
    if (!result) {
        ++state_.failedDispatchCount;
        return;
    }

    state_.checksum += *result;
    ++state_.dispatchCount;
}
