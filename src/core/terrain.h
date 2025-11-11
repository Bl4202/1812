#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

namespace hold {

enum class TerrainType {
    Plains,
    Forest,
    Hill,
    River,
    Fort,
    Town,
    Port,
    Sea
};

struct TerrainProfile {
    int defenseModifier;   // percentage bonus or penalty
    int movementCost;      // action points required to enter
    std::string_view notes;
};

const TerrainProfile& terrain_profile(TerrainType type);
const std::unordered_map<TerrainType, TerrainProfile>& all_terrain_profiles();
std::string to_string(TerrainType type);

}  // namespace hold
