#pragma once

#include "types.h"

// Selectors of WriteWinInOutBits: the layers shown inside window 0, inside window 1, inside the object window, and
// outside every window.
#define WIN_SELECTOR_WIN0_IN 0
#define WIN_SELECTOR_WIN1_IN 1
#define WIN_SELECTOR_OBJ_WIN_IN 2
#define WIN_SELECTOR_OUTSIDE 3

void WriteWinInOutBits(int screen, int selector, u32 bits, int extraBitFlag);
void WriteWinRect(int screen, int window, u16 *rect);
void ClearDispcntBits(int screen, u32 bits);
void CombineDispcntBits(int screen, u32 bits);
