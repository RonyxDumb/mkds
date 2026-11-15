# Codebase Guide

Where things are in this repository, and what each folder holds. Build steps are in [INSTALL.md](../INSTALL.md);
how to work on the code is in [decompiling.md](decompiling.md) and [CONTRIBUTING.md](../CONTRIBUTING.md).

## Top Level

- `src/`: the game's own code, one `.c` file per object or job.
- `include/`: the game's headers, at the same path as their `.c` file (`src/Main/Kart/kart_level.c` ->
  `include/Main/Kart/kart_level.h`).
- `libs/`: the library code linked into the game (SDK, NitroSystem, Wi-Fi libraries, C runtime), with its headers.
- `config/`: how the ROM splits into units: symbols, the source file of each address range, relocations, per version.
- `tools/`: build, check and progress scripts (`configure.py` writes the build; `progress.py` measures matching).
- `docs/`: notes on the compiler and flags, the decompiling workflow, and version differences.
- `progress/`: the progress graph and its history.

## Game Code (`src/Main`)

The code that is always loaded (the ARM9 main binary).

- `src/Main/Kart`: karts: driving, speed, drift, collision responses, the Kart AI, name tags, kart effects.
- `src/Main/Item`: items: item objects (shells, bananas, bombs, Boo), item boxes, holding, throwing and following.
- `src/Main/MapObjects`: course objects: the map object list and kind table, and each kind (Kuribo, Pakkun, Wanwan,
  Dossun, coins, balloons, pipes ...).
- `src/Main/Course`: course data: the course map and its shapes, course colours, course sounds.
- `src/Main/Race`: the race itself: rules, progress and laps, standings, the race HUD, the end of a race, ghosts.
- `src/Main/Menu`: menu screens shared by every mode: title, character and kart select, cup and course select,
  records, the on-screen keyboard.
- `src/Main/Scene`: the scene table and the loop that switches scenes (title, menu, race, results ...).
- `src/Main/Graphics`: models and their animations, fonts and text drawing, screen effects.
- `src/Main/Sound`: sound playback: sequences, sound banks, positional sounds of karts and objects.
- `src/Main/Net`: local wireless play: multiboot (download play), the connection, data sharing between consoles.
- `src/Main/Save`: the save data: records, ghosts, emblems, friend data.
- `src/Main/System`: start-up, heaps, threads, input recording.

## Fast Memory Code (`src/ITCM`)

- `src/ITCM`: code copied into the processor's fast memory at start-up: kart physics (speed, velocity, gravity,
  ground contact), sphere collision, DMA transfers, and the 3D drawing and interrupt code that runs there.

## Overlays (`src/00` to `src/03`)

Code loaded only while it is needed; each overlay keeps its own folder.

- `src/00`: online play over Nintendo Wi-Fi Connection: the Wi-Fi menus (`src/00/Menu`), the Wi-Fi menu scene
  (`src/00/Scene`), and the online libraries in `src/00/Lib` (DWC, GameSpy, CPS, NitroWiFi).
- `src/01`: menus and modes outside the race core: records and time attack menus, Mission Run (its menus, bosses and
  objects in `src/01/MapObjects`, its HUD in `src/01/Race`), the logo and test scenes (`src/01/Scene`), the ending
  (`src/01/Menu`), and one graphics helper in `src/01/Graphics`.
- `src/02`: a small overlay that only holds a large heap buffer (`src/02/Net`).
- `src/03`: the Nintendo Wi-Fi Connection setup screens: access point settings and search (`src/03/Net`), their
  menus and error screens (`src/03/Menu`), and their own graphics, sound and system helpers (`src/03/Graphics`,
  `src/03/Sound`, `src/03/System`).

## Libraries (`libs`)

Library files keep their address names (`code_XXXXXXXX.c`); their functions carry the library's names.

- `libs/NitroSDK`: the console SDK, one folder per module (os, fs, gx, snd, wm, mb, card ...).
- `libs/NitroSystem`: the higher-level graphics and sound library (fnd, g2d, g3d, gfd, snd).
- `libs/NitroDWC`: the Wi-Fi Connection library parts linked into the main binary (account, backup).
- `libs/spl`: the particle library.
- `libs/msl`: the C runtime (strings, printing, math).
- `libs/mathlib`: the compiler's arithmetic routines (division, floating point), written in assembly.

## Headers (`include`)

- `include/Main`, `include/ITCM`, `include/00`, `include/01`, `include/02`, `include/03`: the game's headers, mirroring
  `src/`.
- `include/types.h`: the base types and the project's own helper macros.
- Library headers live next to their code in `libs/<library>/<module>/include`.

## Finding Things

- A function by name: `git grep -n "Name("`; every function in the ROM is named.
- What an address holds: `config/usa/arm9/symbols.txt` (main binary) and `config/usa/arm9/overlays/ov00N/` (overlays).
- Which source file covers an address: `config/usa/arm9/delinks.txt`.
- Matching status of a file: `python3 tools/progress.py` after a build.
