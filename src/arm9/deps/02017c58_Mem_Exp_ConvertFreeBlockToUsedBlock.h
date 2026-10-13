#pragma once
/* Function-specific inferred declarations. */
void MIi_CpuClear32(undefined4 param_1,undefined4 *param_2,int param_3);
int Mem_ExpHeapMemoryBlockList_Insert(int *param_1,int param_2,int param_3);
uint Mem_ExpHeapMemoryBlockList_Remove(uint *param_1,int param_2);
int Mem_Exp_ConvertFreeBlockToUsedBlock(int param_1,undefined4 param_2,int param_3,int param_4,ushort param_5);
undefined2 * Mem_Exp_InitializeMemoryBlock(uint param_1,undefined2 param_2);
void Mem_GetMemoryBlockRegion(int *param_1,int param_2);
#define uRam02017de4 (*(undefined4 *)(uintptr_t)0x2017de4u)
#define uRam02017de8 (*(undefined4 *)(uintptr_t)0x2017de8u)
