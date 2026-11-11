#pragma once

#include "types.h"
#include "Main/Unknown/code_020b4000.h"

typedef struct KeyboardRect KeyboardRect;

void SetupKeyboardLayoutOther3(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount);
void SetupKeyboardLayoutOther2(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount);
void SetupKeyboardLayoutOther1(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount);
void SetupKeyboardLayoutAscii(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount);
