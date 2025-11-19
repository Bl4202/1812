#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <unordered_map>

namespace hold {

enum class UnitRangeType {
    Melee,
    Ranged,
    Mixed
};

enum class UnitTypeId {
    Militia,
    LineInfantry,
    Riflemen,
    Cavalry,
    LightArtillery,
    HeavyArtillery,
    SupplyWagon,
    Officer,
    Warship,
    Frigate
};

struct RangeProfile {
    int minRange;
    int maxRange;
};

struct UnitTemplate {
    std::string name;
    int cost;
    int movement;
    RangeProfile range;
    UnitRangeType rangeType;
    std::string role;
};

struct UnitStats {
    int morale = 100;
    int supply = 100;
    bool fortified = false;
};

class Unit {
  public:
    Unit(UnitTypeId type, int ownerId);

    UnitTypeId type() const { return type_; }
    int owner() const { return owner_; }

    const UnitTemplate& templ() const;
    const UnitStats& stats() const { return stats_; }
    UnitStats& mutable_stats() { return stats_; }

  private:
    UnitTypeId type_;
    int owner_;
    UnitStats stats_{};
};

const UnitTemplate& unit_template(UnitTypeId id);
const std::unordered_map<UnitTypeId, UnitTemplate>& all_unit_templates();
std::string to_string(UnitTypeId id);

}  // namespace hold
