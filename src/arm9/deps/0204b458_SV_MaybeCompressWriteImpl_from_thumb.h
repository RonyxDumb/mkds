#pragma once
/* Function-specific inferred declarations. */
void CalculateCRCChecksum_from_thumb(int param_1,int param_2,int param_3);
void CardIsNotBusy(void);
bool Card_RequestStreamCommand(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9);
void DC_SomeClean(uint param_1,int param_2);
void EncryptSaveData_from_thumb(uint *param_1,int param_2);
undefined4 SV_MaybeCompressWriteImpl_from_thumb(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6);
undefined4 func_0204b518(void);
#define piRam0204b510 (*(int **)(uintptr_t)0x204b510u)
#define uRam0204b514 (*(undefined4 *)(uintptr_t)0x204b514u)
