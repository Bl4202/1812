#include "core/unit.h"

#include <array>
#include <stdexcept>

namespace hold {
namespace {

constexpr RangeProfile kRangeMelee{1, 1};
constexpr RangeProfile kRangeRifle{2, 2};
constexpr RangeProfile kRangeLightArtillery{2, 3};
constexpr RangeProfile kRangeHeavyArtillery{3, 4};
constexpr RangeProfile kRangeWarship{2, 3};
constexpr RangeProfile kRangeFrigate{2, 4};

const UnitTemplate kTemplates[] = {
    {"Militia", 500, 3, kRangeMelee, UnitRangeType::Melee, "Cheap garrison infantry"},
    {"Line Infantry", 1000, 4, kRangeMelee, UnitRangeType::Melee, "Mainline troops"},
    {"Riflemen", 1500, 4, kRangeRifle, UnitRangeType::Ranged, "Skirmishers"},
    {"Cavalry", 2000, 6, kRangeMelee, UnitRangeType::Melee, "Flanking and pursuit"},
    {"Light Artillery", 2500, 3, kRangeLightArtillery, UnitRangeType::Ranged, "Mobile field cannon"},
    {"Heavy Artillery", 3500, 2, kRangeHeavyArtillery, UnitRangeType::Ranged, "Siege and fort defense"},
    {"Supply Wagon", 1000, 4, {0, 0}, UnitRangeType::Mixed, "Resupply adjacent units"},
    {"Officer", 3000, 4, kRangeMelee, UnitRangeType::Melee, "Morale and stat booster"},
    {"Warship", 4000, 6, kRangeWarship, UnitRangeType::Ranged, "Naval gunship"},
    {"Frigate", 5500, 7, kRangeFrigate, UnitRangeType::Ranged, "Heavy naval vessel"},
};

constexpr std::array<const char*, 10> kNames = {
    "Militia", "LineInfantry", "Riflemen", "Cavalry", "LightArtillery",
    "HeavyArtillery", "SupplyWagon", "Officer", "Warship", "Frigate"
};

}  // namespace

Unit::Unit(UnitTypeId type, int ownerId) : type_(type), owner_(ownerId) {}

const UnitTemplate& Unit::templ() const {
    auto index = static_cast<std::size_t>(type_);
    if (index >= std::size(kTemplates)) {
        throw std::out_of_range("invalid unit type");
    }
    return kTemplates[index];
}

const UnitTemplate& unit_template(UnitTypeId id) {
    auto index = static_cast<std::size_t>(id);
    if (index >= std::size(kTemplates)) {
        throw std::out_of_range("invalid unit type");
    }
    return kTemplates[index];
}

const std::unordered_map<UnitTypeId, UnitTemplate>& all_unit_templates() {
    static const std::unordered_map<UnitTypeId, UnitTemplate> templates = {
        {UnitTypeId::Militia, kTemplates[0]},
        {UnitTypeId::LineInfantry, kTemplates[1]},
        {UnitTypeId::Riflemen, kTemplates[2]},
        {UnitTypeId::Cavalry, kTemplates[3]},
        {UnitTypeId::LightArtillery, kTemplates[4]},
        {UnitTypeId::HeavyArtillery, kTemplates[5]},
        {UnitTypeId::SupplyWagon, kTemplates[6]},
        {UnitTypeId::Officer, kTemplates[7]},
        {UnitTypeId::Warship, kTemplates[8]},
        {UnitTypeId::Frigate, kTemplates[9]},
    };
    return templates;
}

std::string to_string(UnitTypeId id) {
    auto index = static_cast<std::size_t>(id);
    if (index >= kNames.size()) {
        return "Unknown";
    }
    return kNames[index];
}

}  // namespace hold
