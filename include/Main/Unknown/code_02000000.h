#pragma once

#include "types.h"
#include "Main/Unknown/code_02000b44.h"
#include "Main/Unknown/code_02000920.h"

// Declared here until the code that defines them is decompiled.
void CpuSet(const void *src, void *dst, u32 ctrl);
void WaitByLoop(s32 n);
void VBlankIntrWait(void);
s32 func_0200806c(void *a, void *b, u16 c, void *d);
