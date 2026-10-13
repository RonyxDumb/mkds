#pragma once
/* Function-specific inferred declarations. */
bool ArcEntry_ValidateNarcHeader(uint param_1);
void Fs_Archive_Initialize(int param_1);
undefined4 Fs_Archive_LoadFromFatFnt(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8);
undefined4 Fs_RegisterArchive(undefined4 *param_1,undefined4 param_2,undefined4 param_3);
void Fs_UnregisterArchive(undefined4 *param_1);
undefined4 MountMountEntryFrom(int param_1,char *param_2,int param_3);
size_t strlen(char *__s);
#define uRam02018498 (*(uint *)(uintptr_t)0x2018498u)
#define uRam0201849c (*(uint *)(uintptr_t)0x201849cu)
