#pragma once
/* Function-specific inferred declarations. */
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void AllocateGhostHolder(undefined4 param_1);
#define pcRam02061424 (*(__typeof__(Mem_AllocateHeap) **)(uintptr_t)0x2061424u)
