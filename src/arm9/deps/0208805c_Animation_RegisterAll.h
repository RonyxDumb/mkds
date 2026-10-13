#pragma once
/* Function-specific inferred declarations. */
uint Anim_GetNeededBlockSize(char *param_1,int param_2);
void Anim_NSBCA_LoadGetJNT0Block(undefined4 param_1);
void Animation_RegisterAll(int param_1,undefined4 param_2,int param_3);
int BMA0_LoadRawData(int param_1,int param_2);
int BTA0_LoadRawData(int param_1,int param_2);
int BTP0_LoadRawData(int param_1,int param_2);
int BVA0_LoadRawData(int param_1,int param_2);
int JNT0_LoadJointByIdx(int param_1,int param_2);
void MaybeCreateAnimationBlock(undefined4 *param_1,char *param_2,undefined4 param_3,undefined4 param_4);
void MaybeLoadBMA0Format(undefined4 param_1);
void MaybeLoadBTA0Format(undefined4 param_1);
void MaybeLoadBTP0Format(undefined4 param_1);
void MaybeLoadBVA0Format(undefined4 param_1);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
#define DAT_020881ac (*(undefined4 **)(uintptr_t)0x20881acu)
