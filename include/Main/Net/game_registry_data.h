#pragma once

#include "types.h"

// The game registry record MB_RegisterFile reads: the ROM file path, the game name and introduction (the last two are
// filled in by SetGameRegistryTexts), the two icon file names, the game group id and the most players.
extern void *const gGameRegistry[15];
