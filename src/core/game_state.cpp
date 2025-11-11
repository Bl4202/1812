#include "core/game_state.h"

#include <stdexcept>

namespace hold {

GameState::GameState(MapSize size, int playerCount)
    : mapSize_(size),
      tiles_(size.width * size.height, MapTile{TerrainType::Plains, std::nullopt}),
      economies_(playerCount) {}

PlayerEconomy& GameState::economy(int playerId) {
    if (playerId < 0 || playerId >= static_cast<int>(economies_.size())) {
        throw std::out_of_range("invalid player id");
    }
    return economies_[playerId];
}

const PlayerEconomy& GameState::economy(int playerId) const {
    if (playerId < 0 || playerId >= static_cast<int>(economies_.size())) {
        throw std::out_of_range("invalid player id");
    }
    return economies_[playerId];
}

bool in_bounds(const GameState& state, Position pos) {
    return pos.x >= 0 && pos.y >= 0 && pos.x < state.map_size().width &&
           pos.y < state.map_size().height;
}

}  // namespace hold
