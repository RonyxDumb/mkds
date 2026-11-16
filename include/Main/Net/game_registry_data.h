#pragma once

#include "types.h"

// The game registry record MB_RegisterFile reads: three text pointers (the last two are filled in by
// SetGlobalBAN_from_thumb), two icon file names, the game id and the player count.
extern void *const g_GlobalBAN[15];
