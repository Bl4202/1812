#include "systems/turn_system.h"

#include <algorithm>

namespace hold {

void TurnSystem::add_rule(ActionRule rule) {
    rules_.push_back(std::move(rule));
}

bool TurnSystem::validate_action(const GameState& state, const UnitAction& action) const {
    return std::all_of(rules_.begin(), rules_.end(), [&](const ActionRule& rule) {
        return !rule.validator || rule.validator(state, action);
    });
}

void TurnSystem::apply_action(GameState& state, const UnitAction& action) const {
    for (const auto& rule : rules_) {
        if (rule.executor) {
            rule.executor(state, action);
        }
    }
}

void TurnSystem::end_turn(GameState& state) const {
    state.increment_turn();
    state.set_active_player((state.active_player() + 1) % 2);
    for (auto& unit : state.units()) {
        unit.mutable_stats().fortified = false;
    }
}

}  // namespace hold
