#pragma once

#include "types.h"

void ExitTail(int status);
void exit(int status);
void abort(void);

// Function pointers called and cleared by ExitTail (data_0217e984) and exit (data_0217e988).
extern void (*data_0217e984)(void);
extern void (*data_0217e988)(void);
// Count of the entries of gExitFunctions that ExitTail calls, last first.
extern int gExitFunctionCount;
extern void (*gExitFunctions[64])(void);
// Set by abort; exit reads it.
extern int gAborted;
