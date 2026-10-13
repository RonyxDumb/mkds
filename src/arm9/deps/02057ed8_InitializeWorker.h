#pragma once
/* Function-specific inferred declarations. */
void InitializeWorker(undefined4 param_1);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
undefined4 Mem_AllocateHeapAligned(uint param_1,undefined4 param_2,undefined4 param_3);
void Os_Thread_Create(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6);
void Os_Thread_WakeUpDirect(int param_1);
#define puRam02057f84 (*(undefined4 **)(uintptr_t)0x2057f84u)
#define uRam02057f88 (*(undefined4 *)(uintptr_t)0x2057f88u)
