#pragma once
/* Function-specific inferred declarations. */
int Mem_FindTopParentHeapHead(undefined4 param_1,uint param_2);
void Mem_FindGlobalTopParentHeapHead(undefined4 param_1);
#define pcRam02017560 (*(__typeof__(Mem_FindTopParentHeapHead) **)(uintptr_t)0x2017560u)
#define uRam02017564 (*(undefined4 *)(uintptr_t)0x2017564u)
