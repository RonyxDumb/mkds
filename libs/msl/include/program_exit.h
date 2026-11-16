#pragma once

#include "types.h"

void ExitTail(int status);
void CheckZetaInvokeBeta(int status);
void OnAssertionFailed(void);

// Function pointers called and cleared by ExitTail (gExitTailCallback) and CheckZetaInvokeBeta (g_BetaFunc).
extern void (*gExitTailCallback)(void);
extern void (*g_BetaFunc)(void);
// Count of the entries of gExitFunctions that ExitTail calls, last first.
extern int gExitFunctionCount;
extern void (*gExitFunctions[64])(void);
// Set by OnAssertionFailed; CheckZetaInvokeBeta reads it.
extern int g_ZetaValue;
