#pragma once
/* Function-specific inferred declarations. */
void InitializeSystemContext(undefined4 param_1);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
undefined4 Mem_Frame_Create(int param_1,int param_2);
undefined4 Os_GetMemoryRegionEndAddress(int param_1);
undefined4 Os_GetMemoryRegionStartAddress(int param_1);
void PopulateSystemContext(void);
#define puRam0204afcc (*(undefined4 **)(uintptr_t)0x204afccu)
