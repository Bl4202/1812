# Hold the Line – Tactical Design Dossier

## Concept Overview
"Hold the Line" is a turn-based strategy game set during the War of 1812. Players command American forces against the British Empire, Canadian Militia, and the Native Confederation in a campaign defined by punishing combat, morale attrition, and scarce supplies. The aesthetics marry gritty battlefield realism with stylized historical presentation, underscoring the sense that victory is hard-earned and often pyrrhic.

## Core Gameplay Systems
### Turn Structure
- Classic IGOUGO flow: players alternate turns.
- Each unit may **move, attack, capture, or fortify** once per turn.
- Fortifying consumes the action but grants a temporary defensive bonus and morale bump.

### Victory Conditions
- **Capture the enemy HQ** to force a strategic surrender.
- **Eliminate all enemy units** to achieve total battlefield dominance.
- **Hold designated objectives for X turns** to secure a defensive victory.

### Resources and Economy
- **Gold**: Earned from controlled towns and ports. Spent to deploy reinforcements and replace losses.
- **Supplies**: Consumed to maintain unit effectiveness. Supply shortages erode morale, reducing accuracy and defense.

### Terrain Effects
| Terrain | Defense Modifier | Movement Cost | Notes |
| --- | --- | --- | --- |
| Plains | 0 | 1 | Open ground for cavalry charges but vulnerable to artillery. |
| Forest | +20 | 2 | Conceals skirmishers; dampens artillery effectiveness. |
| Hill | +30 | 2 | Elevation grants range visibility and defensive advantage. |
| River | -20 | 3 | Crossing disorder lowers morale; ideal ambush site. |
| Fort | +50 | 1 | Heavily fortified; resupply and morale refuge. |
| Town | +30 | 1 | Provides income and minor reinforcements. |
| Port | +40 | 1 | Naval deployment hub and gold income source. |
| Sea | 0 | 1 | Naval movement grid; exposed to weather shifts. |

### Weather System
- **Rain**: Reduces ranged attack accuracy by a flat percentage.
- **Snow**: Halves movement points, forcing meticulous planning.
- **Fog**: Shrinks visibility radius, promoting reconnaissance play.

## Unit Roster
| Unit | Cost | Move | Range | Battlefield Role |
| --- | --- | --- | --- | --- |
| Militia | 500 | 3 | 1 | Inexpensive garrison infantry suited for towns and forts. |
| Line Infantry | 1000 | 4 | 1 | Core line troops balancing offense and resilience. |
| Riflemen | 1500 | 4 | 2 | Skirmishers with extended range for harassment. |
| Cavalry | 2000 | 6 | 1 | Mobile flanking force ideal for pursuit and disruption. |
| Light Artillery | 2500 | 3 | 2–3 | Mobile cannons for field support. |
| Heavy Artillery | 3500 | 2 | 3–4 | Siege specialists anchoring defensive lines. |
| Supply Wagon | 1000 | 4 | — | Restores supplies to adjacent allies; critical for morale. |
| Officer | 3000 | 4 | 1 | Command unit granting morale and stat buffs nearby. |
| Warship | 4000 | 6 | 2–3 | Naval gunship for coastal bombardment. |
| Frigate | 5500 | 7 | 2–4 | Heavy naval vessel with superior range and durability. |

## Campaign Structure
1. **Crossing the Detroit** (Difficulty 2)
   - Objective: Capture Fort Malden across the river.
   - Player Forces: 2 Line Infantry, 1 Militia, 1 Light Artillery, 1 Officer, 1 Supply Wagon.
   - Enemy Forces: 3 Line Infantry, 1 Riflemen, 1 Light Artillery, 1 Officer.
   - Map: 22×16.
   - Tactical Notes: Bait defenders at the river crossing, shield artillery, and secure the fort.

2. **Queenston Heights** (Difficulty 4)
   - Objective: Capture British hill positions.
   - Player Forces: 3 Line Infantry, 1 Militia, 1 Light Artillery, 1 Officer, 1 Supply Wagon.
   - Enemy Forces: 2 Line Infantry, 1 Riflemen, 1 Heavy Artillery, 1 Officer, reinforcements after Turn 5.
   - Map: 25×18.
   - Tactical Notes: Neutralize artillery first, maintain cohesive formations, rotate weakened units to the rear.

3. **Battle of Lake Erie** (Difficulty 5)
   - Objective: Sink the British flagship "Detroit".
   - Player Forces: 1 Frigate, 2 Warships, 1 Supply Ship.
   - Enemy Forces: 1 Frigate, 3 Warships, 2 Gunboats, 1 Supply Ship.
   - Map: 24×12.
   - Tactical Notes: Keep optimal firing distance, exploit diagonal maneuvers, concentrate fire on the flagship.

4. **Burning of Washington** (Difficulty 6)
   - Objective: Delay British forces for 15 turns.
   - Player Forces: 2 Line Infantry, 3 Militia, 2 Light Artillery, 1 Officer, 1 Supply Wagon.
   - Enemy Forces: 4 Line Infantry, 3 Riflemen, 2 Heavy Artillery, 2 Cavalry, 1 Officer.
   - Map: 28×20.
   - Tactical Notes: Hold choke points, eliminate cavalry quickly, conduct phased retreats toward the Capitol HQ.

5. **Battle of New Orleans** (Difficulty 8)
   - Objective: Destroy all British siege artillery.
   - Player Forces: 3 Line Infantry, 2 Riflemen, 2 Heavy Artillery, 1 Officer (Jackson), 1 Cavalry, 1 Supply Wagon.
   - Enemy Forces: 6 Line Infantry, 4 Riflemen, 3 Heavy Artillery, 3 Cavalry, 2 Officers.
   - Map: 30×22.
   - Tactical Notes: Prioritize siege guns, safeguard supply corridors, neutralize officers to blunt enemy buffs.

## Artificial Intelligence Doctrine
- **Architecture**: Adaptive beam-search tactical AI combining terrain analysis, morale tracking, and influence-map evaluation.
- **Action Generation**: For each unit, considers movement, attack, capture, and fortify actions. Beam search selects the globally optimal plan within depth constraints.
- **Target Priorities**: Favors high-defense tiles, focuses on eliminating officers and artillery, and avoids overextension when influence maps show overmatch.
- **Difficulty Scaling**:
  - Normal: Beam width 40, depth 2.
  - Hard: Beam width 80, depth 3.
  - Insane: Beam width 120, depth 4.

## Tone and Player Experience
Battles are unforgiving. Even optimal tactics may lead to pyrrhic victories, reinforcing the historical grimness of the War of 1812. The player receives formal military briefings, after-action reports, and stern reminders that morale and supply discipline are the difference between survival and annihilation.

## Notes for Further Development
- Incorporate morale penalties when units fight while unsupplied.
- Develop event scripting that reflects historical setbacks and reinforcements.
- Create officer personality traits affecting nearby unit behavior.
- Integrate dynamic weather transitions influencing long-form operations.
- Leverage the existing AI codebase to tune evaluation heuristics for morale impact.

## Technical Architecture Snapshot
- **Core Library (`src/core/`)**
  - `terrain.*`: Enumerations and balance profiles for each tile type, mirroring dossier modifiers.
  - `unit.*`: Unit template registry encapsulating cost, mobility, range bands, and battlefield roles.
  - `game_state.*`: State container for map tiles, active units, weather status, and player economies.
- **Systems Layer (`src/systems/`)**
  - `turn_system.*`: Extensible action rule processor supporting move, attack, capture, fortify, and resupply verbs.
- **Executable Stub (`src/main.cpp`)**
  - Demonstrates initializing a scenario, applying a fortify action, and rotating the active player.

This scaffold establishes the simulation backbone required for morale, supply, and AI subsystems described above.
