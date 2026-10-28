#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.
void CpuSet(const void *src, void *dst, u32 ctrl);
void WaitByLoop(s32 n);
void VBlankIntrWait(void);
void func_02001000(void);
void func_02000934(void *p0);
unsigned int func_02000b44(unsigned int p0);
