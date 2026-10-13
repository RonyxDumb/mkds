#pragma once
/* Function-specific inferred declarations. */
undefined4 AllocateHeapsAndBuffers(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5,undefined4 *param_6);
undefined4 GetSoundBufferAllocationSize(int param_1);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void Mem_CreateChildFrameHeapFromHead(uint param_1,undefined4 param_2);
void Mem_CreateChildFrameHeapFromTail(uint param_1,undefined4 param_2);
int Mem_GetExpHeapTotalFreeSize(int param_1);
#define psRam02039ee8 (*(short **)(uintptr_t)0x2039ee8u)
