#pragma once
/* Function-specific inferred declarations. */
void IntrusiveListWrapper_InsertLast(uint param_1,int param_2);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
uint Model_CreateFromNsbmdNsbtxMetaCopy(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4);
int Nsbmd_GetMDL0Block(int param_1);
int Nsbtx_GetTEX0Block(uint param_1);
void StructML_MaybeInnerLoadModel(int param_1,int param_2,int param_3);
undefined4 Tex0Block_MaybePrepareFields(int param_1);
uint func_02010168(int param_1,undefined4 param_2);
#define uRam02084c4c (*(undefined4 *)(uintptr_t)0x2084c4cu)
#define uRam02084c50 (*(uint *)(uintptr_t)0x2084c50u)
