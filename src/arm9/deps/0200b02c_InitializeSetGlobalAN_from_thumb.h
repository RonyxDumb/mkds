#pragma once
/* Function-specific inferred declarations. */
void InitializeSetGlobalAN_from_thumb(int param_1,int param_2);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_Create(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6);
void Os_Thread_WakeUpDirect(int param_1);
void StructANN_Create_from_thumb(undefined4 param_1);
#define piRam0200b084 (*(int **)(uintptr_t)0x200b084u)
#define uRam0200b088 (*(undefined4 *)(uintptr_t)0x200b088u)
