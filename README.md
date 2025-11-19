# Hold the Line – War of 1812 Tactical Brief

This repository contains the design dossier and emerging codebase for **Hold the Line**,
a punishing War of 1812 strategy experience built in the spirit of Advance Wars with
gritty historical realism. The full breakdown of systems, units, campaign scenarios,
and AI doctrine lives in [HOLD_THE_LINE_DESIGN.md](HOLD_THE_LINE_DESIGN.md).

## Contents
- `HOLD_THE_LINE_DESIGN.md` – Complete game design reference covering core mechanics,
  campaign structure, and development notes.
- `src/` – Foundational C++ structures for terrain, unit templates, and the turn system.
- `CMakeLists.txt` – Build script for generating the prototype executable.

## Development
1. Configure a build directory: `cmake -S . -B build`.
2. Compile the prototype: `cmake --build build`.
3. Run the demonstration executable: `./build/hold_the_line`.

## Notes
- Tone targets formal military briefings and bleak historical authenticity.
- Systems emphasize morale attrition, supply chains, and unforgiving tactical decisions.
