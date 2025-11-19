#pragma once

#include "core/game_state.h"

#include <functional>
#include <vector>

namespace hold {

struct UnitAction {
    enum class Type { Move, Attack, Capture, Fortify, Resupply } type;
    int unitIndex;
    Position target;
};

using ActionValidator = std::function<bool(const GameState&, const UnitAction&)>;
using ActionExecutor = std::function<void(GameState&, const UnitAction&)>;

struct ActionRule {
    ActionValidator validator;
    ActionExecutor executor;
};

class TurnSystem {
  public:
    void add_rule(ActionRule rule);

    bool validate_action(const GameState& state, const UnitAction& action) const;
    void apply_action(GameState& state, const UnitAction& action) const;

    void end_turn(GameState& state) const;

  private:
    std::vector<ActionRule> rules_;
};

}  // namespace hold
