#pragma once
/* Function-specific inferred declarations. */
void Animation_CreateFrom(undefined4 param_1,int param_2,int param_3,uint param_4,int param_5);
void Animation_Register(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5);
void Animation_RegisterAll(int param_1,undefined4 param_2,int param_3);
void Animation_SetAt(int param_1,int param_2);
int BTP0_LoadRawData(int param_1,int param_2);
void LoadModelBMFromMD(undefined4 param_1,undefined4 *param_2,byte *param_3);
void MaybeLoadBTP0Format(undefined4 param_1);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
uint Model_CreateFromNsbmdWithoutCullReverse(int param_1,undefined4 param_2);
int _snprintf(char *__s,size_t __maxlen,char *__format,...);
int find_buf_fn_from_thumb(undefined4 param_1);
#define pcRam0208aa20 (*(char **)(uintptr_t)0x208aa20u)
#define pcRam0208aa24 (*(char **)(uintptr_t)0x208aa24u)
#define pcRam0208aa28 (*(char **)(uintptr_t)0x208aa28u)
#define pcRam0208aa2c (*(char **)(uintptr_t)0x208aa2cu)
