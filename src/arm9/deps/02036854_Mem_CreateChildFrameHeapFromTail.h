#pragma once
/* Function-specific inferred declarations. */
void Mem_CreateChildFrameHeapFromTail(uint param_1,undefined4 param_2);
void Mem_Exp_Allocate(undefined4 param_1,int param_2,int param_3);
void Mem_Frame_Allocate(int param_1,int param_2,int param_3);
undefined4 Mem_Frame_Create(int param_1,int param_2);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
#define uRam020368d8 (*(uint *)(uintptr_t)0x20368d8u)
#define uRam020368dc (*(uint *)(uintptr_t)0x20368dcu)
