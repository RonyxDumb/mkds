#pragma once
/* Function-specific inferred declarations. */
int Bmg_GetRawStringPointer_from_thumb(undefined4 param_1,undefined4 param_2);
int ComputeValueInterpolation_from_thumb(int param_1,int param_2,int param_3,int param_4,int param_5);
void Keyboard_SwitchFn10_from_thumb(void);
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
void TextSystem_CloseDialog_from_thumb(void);
void TextSystem_DisplayProgressDialog_TopScreen_from_thumb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7);
void TextSystem_DisplayProgressDialog_from_thumb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6);
void TextSystem_DisplaySingleButtonDialog_from_thumb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6);
undefined4 TextSystem_IsButton2Focused_from_thumb(void);
undefined4 TextSystem_IsDialogFinished_from_thumb(void);
void TextSystem_SetFadeInSseqId_from_thumb(undefined4 param_1);
undefined4 TextSystem_WasAnyDialogButtonPressed_from_thumb(void);
void WriteFriendListSaveDataSection(void);
void WriteSaveDataSectionHeaderToSaveData_from_thumb(void);
void func_02060cb4(undefined4 param_1,undefined4 param_2);
#define iRam02129134 (*(int *)(uintptr_t)0x2129134u)
#define piRam0212912c (*(int **)(uintptr_t)0x212912cu)
#define psRam02129130 (*(short **)(uintptr_t)0x2129130u)
#define puRam02129138 (*(undefined4 **)(uintptr_t)0x2129138u)
