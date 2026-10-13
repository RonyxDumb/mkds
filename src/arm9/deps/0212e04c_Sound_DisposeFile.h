#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Sound_DisposeFile(int param_1,int param_2,undefined4 param_3);
uint Sound_MaybeGetRawFilePointer(uint param_1);
uint Sound_MaybeSetActiveSdat(undefined4 param_1);
void Sound_SetFileFatDynamicOffsetField(int param_1,undefined4 param_2);

