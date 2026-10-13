#pragma once
/* Function-specific inferred declarations. */
undefined4 Maybe_data_Sound_sound_data(void);
void SetGlobalSdatUsed(undefined4 param_1);
int Sound_GetSarcInfoEntry(uint param_1);
int Sound_GetSwarInfoEntry(uint param_1);
bool Sound_LoadSarc(undefined4 param_1,undefined4 param_2);
bool Sound_LoadSbnkWithFlags(void);
bool Sound_LoadSwar(undefined4 param_1,undefined4 param_2);
uint Sound_MaybeGetRawFilePointer(uint param_1);
uint Sound_MaybeSetActiveSdat(undefined4 param_1);
undefined4 Sound_ReadSdatFromPathImplV2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void Sound_SetFileFatDynamicOffsetField(int param_1,undefined4 param_2);
undefined4 func_02108950(void);
void func_0210e4c8(int param_1);
bool func_0210ed20(undefined4 param_1,int param_2);
#define iRam0210e884 (*(int *)(uintptr_t)0x210e884u)
#define uRam0210e874 (*(undefined4 *)(uintptr_t)0x210e874u)
#define uRam0210e878 (*(uint *)(uintptr_t)0x210e878u)
#define uRam0210e87c (*(undefined4 *)(uintptr_t)0x210e87cu)
#define uRam0210e880 (*(undefined4 *)(uintptr_t)0x210e880u)
