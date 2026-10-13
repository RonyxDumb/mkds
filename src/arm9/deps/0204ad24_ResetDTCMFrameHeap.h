#pragma once
/* Function-specific inferred declarations. */
void Mem_ResetFrameHeap(undefined4 param_1,uint param_2);
void ResetDTCMFrameHeap(void);
#define pcRam0204ad40 (*(__typeof__(Mem_ResetFrameHeap) **)(uintptr_t)0x204ad40u)
#define uRam0204ad3c (*(uint *)(uintptr_t)0x204ad3cu)
