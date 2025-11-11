#include "core/game_state.h"
#include "systems/turn_system.h"

#include <iostream>

int main() {
    using namespace hold;

    GameState state({22, 16}, 2);
    state.economy(0).gold = 1000;
    state.economy(1).gold = 1000;

    state.units().emplace_back(UnitTypeId::LineInfantry, 0);
    state.units().emplace_back(UnitTypeId::LineInfantry, 1);

    TurnSystem turnSystem;
    turnSystem.add_rule({
        .validator = [](const GameState&, const UnitAction&) { return true; },
        .executor = [](GameState& state, const UnitAction& action) {
            if (action.type == UnitAction::Type::Fortify &&
                action.unitIndex >= 0 &&
                action.unitIndex < static_cast<int>(state.units().size())) {
                state.units()[action.unitIndex].mutable_stats().fortified = true;
            }
        }
    });

    UnitAction fortify{UnitAction::Type::Fortify, 0, Position{0, 0}};
    if (turnSystem.validate_action(state, fortify)) {
        turnSystem.apply_action(state, fortify);
    }

    std::cout << "Turn: " << state.turn_counter() << "\n";
    std::cout << "Active Player: " << state.active_player() << "\n";
    std::cout << "Unit 0 fortified: " << std::boolalpha
              << state.units()[0].stats().fortified << "\n";

    turnSystem.end_turn(state);

    std::cout << "Turn: " << state.turn_counter() << "\n";
    std::cout << "Active Player: " << state.active_player() << "\n";
}
