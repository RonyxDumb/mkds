#pragma once
/* Function-specific inferred declarations. */
int Sound_AllocateReadEntireFile(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5);
uint Sound_GetActiveSdat(void);
uint Sound_MaybeGetRawFilePointer(uint param_1);
int Sound_PrepareSarcData(undefined4 param_1,undefined4 param_2,int param_3);
void Sound_SetFileFatDynamicOffsetField(int param_1,undefined4 param_2);
#define uRam0212e35c (*(undefined4 *)(uintptr_t)0x212e35cu)
