#include "core/terrain.h"

#include <array>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace hold {
namespace {

constexpr TerrainProfile kProfiles[] = {
    {0, 1, "Open ground favoring cavalry charges but vulnerable to artillery."},
    {20, 2, "Dense cover for skirmishers; artillery less effective."},
    {30, 2, "Elevated line of fire with morale benefits."},
    {-20, 3, "Crossing disrupts formations; ideal ambush zone."},
    {50, 1, "Impregnable fortification enabling resupply."},
    {30, 1, "Population center providing income."},
    {40, 1, "Naval deployment hub and economic anchor."},
    {0, 1, "Sea lane vulnerable to weather shifts."},
};

constexpr std::array<const char*, 8> kNames = {
    "Plains", "Forest", "Hill", "River", "Fort", "Town", "Port", "Sea"
};

}  // namespace

const TerrainProfile& terrain_profile(TerrainType type) {
    auto index = static_cast<std::size_t>(type);
    if (index >= std::size(kProfiles)) {
        throw std::out_of_range("invalid terrain type");
    }
    return kProfiles[index];
}

const std::unordered_map<TerrainType, TerrainProfile>& all_terrain_profiles() {
    static const std::unordered_map<TerrainType, TerrainProfile> profiles = {
        {TerrainType::Plains, kProfiles[0]},
        {TerrainType::Forest, kProfiles[1]},
        {TerrainType::Hill, kProfiles[2]},
        {TerrainType::River, kProfiles[3]},
        {TerrainType::Fort, kProfiles[4]},
        {TerrainType::Town, kProfiles[5]},
        {TerrainType::Port, kProfiles[6]},
        {TerrainType::Sea, kProfiles[7]},
    };
    return profiles;
}

std::string to_string(TerrainType type) {
    auto index = static_cast<std::size_t>(type);
    if (index >= kNames.size()) {
        return "Unknown";
    }
    return kNames[index];
}

}  // namespace hold
