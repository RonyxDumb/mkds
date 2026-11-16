#pragma once

#include "types.h"

void ExitTail(int status);
void exit(int status);
void abort(void);

// Function pointers called and cleared by ExitTail (gExitTailCallback) and exit (gExitCallback).
extern void (*gExitTailCallback)(void);
extern void (*gExitCallback)(void);
// Count of the entries of gExitFunctions that ExitTail calls, last first.
extern int gExitFunctionCount;
extern void (*gExitFunctions[64])(void);
// Set by abort; exit reads it.
extern int gAborted;
