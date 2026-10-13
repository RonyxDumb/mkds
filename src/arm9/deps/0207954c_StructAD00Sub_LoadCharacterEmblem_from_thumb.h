#pragma once
/* Function-specific inferred declarations. */
void Anim_NSBCA_LoadGetJNT0Block(undefined4 param_1);
void Animation_CreateFrom(undefined4 param_1,int param_2,int param_3,uint param_4,int param_5);
int Animation_GetCurrentLength(int param_1);
void Animation_Register(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5);
void Animation_RegisterAll(int param_1,undefined4 param_2,int param_3);
void Animation_SetAt(int param_1,int param_2);
void FX_Div(void);
void FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(undefined4 param_1);
int FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(undefined4 param_1);
char * FormatCharacterEmblemNsbcaPath(undefined4 param_1,int param_2);
char * FormatCharacterEmblemNsbmdPath(int param_1,int param_2);
char * FormatCharacterEmblemNsbtxPath(int param_1,int param_2);
uint GetRacerAnimationIndex(int param_1);
int JNT0_LoadJointByIdx(int param_1,int param_2);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void ModelBlock_SomeMatFn(undefined4 param_1,uint param_2);
uint Model_CreateFromNsbmdNsbtxMetaCopy(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4);
void Model_Render(int param_1);
void StructAD00Sub_LoadCharacterEmblem_from_thumb(uint *param_1,undefined4 param_2,int param_3);
undefined8 _s32_div_f(uint param_1,uint param_2);
#define iRam02079670 (*(int *)(uintptr_t)0x2079670u)
#define piRam02079674 (*(int **)(uintptr_t)0x2079674u)
