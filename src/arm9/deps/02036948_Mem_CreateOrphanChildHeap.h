#pragma once
/* Function-specific inferred declarations. */
void Mem_CreateOrphanChildHeap(uint param_1);
void Mem_Exp_Allocate(undefined4 param_1,int param_2,int param_3);
uint Mem_Exp_GetAllocatableSize(int param_1,int param_2);
void Mem_Frame_Allocate(int param_1,int param_2,int param_3);
undefined4 Mem_Frame_Create(int param_1,int param_2);
int Mem_Frame_GetAllocatableSize(int param_1,int param_2);
#define uRam020369f4 (*(uint *)(uintptr_t)0x20369f4u)
#define uRam020369f8 (*(uint *)(uintptr_t)0x20369f8u)
