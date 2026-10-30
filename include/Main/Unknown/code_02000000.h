#pragma once

#include "types.h"
#include "Main/Unknown/code_02000b44.h"
#include "Main/Unknown/code_02000920.h"
#include "Main/Unknown/code_02007ec4.h"

// Declared here until the code that defines them is decompiled.
void CpuSet(const void *src, void *dst, u32 ctrl);
void WaitByLoop(s32 n);
void VBlankIntrWait(void);
