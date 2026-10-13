#pragma once
/* Function-specific inferred declarations. */
ushort GetCurrentPlayerRacerId(void);
undefined4 GetDirectInputUnitIndex(void);
void GetDriverVec354(undefined4 *param_1,int param_2);
void VecFx32_AddScale1(int param_1,uint param_2,uint param_3,int *param_4);
void VecFx32_Subtract(uint param_1,uint param_2,int *param_3);
int Vector3_MaybeNormalize(uint param_1,int *param_2);
int func_020b5250(int param_1);
void func_020b5290(void);
void func_020b5628(int param_1);
void func_020b6a18(undefined4 param_1,undefined4 param_2);
#define uRam020b5624 (*(uint *)(uintptr_t)0x20b5624u)
