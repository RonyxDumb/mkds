#pragma once
/* Function-specific inferred declarations. */
undefined4 IsGlobalANSet_from_thumb(void);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Terminate(void);
uint Os_Thread_GetPriority(int param_1);
void Os_Thread_WakeUpDirect(int param_1);
void StructANN_SomeFn_from_thumb(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4);
#define piRam0200aff0 (*(int **)(uintptr_t)0x200aff0u)
#define uRam0200aff4 (*(uint *)(uintptr_t)0x200aff4u)
