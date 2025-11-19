#pragma once

#include "core/terrain.h"
#include "core/unit.h"

#include <cstdint>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace hold {

struct MapTile {
    TerrainType terrain;
    std::optional<int> structureOwner;  // optional faction ownership
};

struct MapSize {
    int width;
    int height;
};

struct Position {
    int x;
    int y;
};

struct WeatherState {
    enum class Type { Clear, Rain, Snow, Fog } type = Type::Clear;
    int durationTurns = 0;  // 0 indicates persistent until change event
};

struct ActionPointsConfig {
    int baseMovementPoints = 6;
};

struct PlayerEconomy {
    int gold = 0;
    int supply = 0;
};

class GameState {
  public:
    GameState(MapSize size, int playerCount);

    const MapSize& map_size() const { return mapSize_; }
    const std::vector<MapTile>& map_tiles() const { return tiles_; }
    std::vector<MapTile>& mutable_map_tiles() { return tiles_; }

    std::vector<Unit>& units() { return units_; }
    const std::vector<Unit>& units() const { return units_; }

    WeatherState& weather() { return weather_; }
    const WeatherState& weather() const { return weather_; }

    PlayerEconomy& economy(int playerId);
    const PlayerEconomy& economy(int playerId) const;

    int active_player() const { return activePlayer_; }
    void set_active_player(int id) { activePlayer_ = id; }

    int turn_counter() const { return turnCounter_; }
    void increment_turn() { ++turnCounter_; }

  private:
    MapSize mapSize_;
    std::vector<MapTile> tiles_;
    std::vector<Unit> units_;
    WeatherState weather_{};
    std::vector<PlayerEconomy> economies_;
    int activePlayer_ = 0;
    int turnCounter_ = 1;
};

inline int index_for(const GameState& state, Position pos) {
    return pos.y * state.map_size().width + pos.x;
}

bool in_bounds(const GameState& state, Position pos);

}  // namespace hold
