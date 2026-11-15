# Codebase Guide

This page says where things are. To build the project, see [INSTALL.md](../INSTALL.md); for how to work on the code,
see [decompiling.md](decompiling.md) and [CONTRIBUTING.md](../CONTRIBUTING.md).

## Layout

The game's own code is in `src/` and its headers are in `include/`, at the same path: `src/Main/Kart/kart_level.c`
has its declarations in `include/Main/Kart/kart_level.h`. Library code linked into the game lives in `libs/`, each
library with its own headers. `config/` describes how the ROM is cut into units for each version (symbols, which file
covers which addresses, relocations), `tools/` has the build, check and progress scripts, and `progress/` keeps the
progress graph and its history.

## The Main Binary

Most of the game is in `src/Main`, split by what the code is about.

Karts live in `src/Main/Kart`: driving, speed and drift, what happens when a kart hits something, the Kart AI, name
tags and kart effects. Items are in `src/Main/Item`, from the shells, bananas and bombs themselves to item boxes and
how an item is held, thrown or follows a kart. Everything placed on a course (the map object list and every kind of
object, such as Kuribo, Pakkun, Wanwan, coins and balloons) is in `src/Main/MapObjects`, and the course data itself
(the course map, its shapes, colours and sounds) is in `src/Main/Course`.

A race runs through `src/Main/Race`, which has the rules, lap progress, standings, the race HUD, the end of the race
and ghosts. The menu screens that every mode shares, such as the title, character and kart select, cup select,
records and the on-screen keyboard, are in `src/Main/Menu`, and `src/Main/Scene` switches between the title, menus,
race and results.

The rest supports all of that. `src/Main/Graphics` draws models and their animations, text and screen effects;
`src/Main/Sound` plays sequences and the sounds of karts and objects; `src/Main/Net` handles local wireless play,
including download play; `src/Main/Save` reads and writes the save data (records, ghosts, emblems, friends); and
`src/Main/System` covers start-up, heaps, threads and input recording.

## Fast Memory

`src/ITCM` is copied into the processor's fast memory at start-up. It holds the kart physics that run every frame
(speed, velocity, gravity, ground contact), sphere collision, DMA transfers, and the 3D drawing and interrupt code
that is kept there.

## Overlays

Overlays are loaded only while they are needed, and each has its own folder.

`src/00` is online play over Nintendo Wi-Fi Connection. Its menus are in `src/00/Menu`, its scene in
`src/00/Scene`, and the online libraries it brings along (DWC, GameSpy, CPS, NitroWiFi) in `src/00/Lib`.

`src/01` covers the modes around the race: the records and time attack menus and the ending in `src/01/Menu`,
Mission Run's bosses and objects in `src/01/MapObjects` and its HUD in `src/01/Race`, the logo and test scenes in
`src/01/Scene`, and one drawing helper in `src/01/Graphics`.

`src/02` only holds a large heap buffer, in `src/02/Net`.

`src/03` is the Nintendo Wi-Fi Connection setup: access point settings and search in `src/03/Net`, the setup menus
and error screens in `src/03/Menu`, and the graphics, sound and system helpers they use in `src/03/Graphics`,
`src/03/Sound` and `src/03/System`.

The overlay headers mirror this in `include/00`, `include/01`, `include/02` and `include/03`, and the main binary's
in `include/Main` and `include/ITCM`. `include/types.h` has the base types and the project's own helper macros.

## Libraries

`libs/NitroSDK` is the console SDK, one folder per module (os, fs, gx, snd, wm, mb, card and so on).
`libs/NitroSystem` is the graphics and sound library built on top of it. `libs/NitroDWC` has the parts of the Wi-Fi
Connection library that sit in the main binary, `libs/spl` is the particle library, `libs/msl` is the C runtime, and
`libs/mathlib` holds the arithmetic routines the compiler calls for division and floating point.

## Finding Things

Every function in the ROM has a name, so `git grep -n "Name("` finds it. `config/usa/arm9/symbols.txt` (and the
`overlays/` folder next to it) says what each address holds, and `config/usa/arm9/delinks.txt` says which source file
covers it. After a build, `python3 tools/progress.py` shows how much matches.
