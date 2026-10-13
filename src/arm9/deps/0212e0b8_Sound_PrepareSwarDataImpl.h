#pragma once
/* Function-specific inferred declarations. */
void DC_SomeClean(uint param_1,int param_2);
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
int Sound_Context_Allocate(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
uint Sound_GetActiveSdat(void);
uint Sound_MaybeGetRawFilePointer(uint param_1);
int Sound_PrepareSwarDataImpl(undefined4 param_1,int param_2,int param_3);
undefined4 Sound_ReadFile(uint param_1,undefined4 param_2,uint param_3,int param_4);
void Sound_SetFileFatDynamicOffsetField(int param_1,undefined4 param_2);
#define iRam0212e1e4 (*(int *)(uintptr_t)0x212e1e4u)
#define uRam0212e1e8 (*(undefined4 *)(uintptr_t)0x212e1e8u)
