#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
void Os_InsertThread(int param_1);
void Os_RescheduleThread(void);
undefined4 Os_RestoreIrq(void);
undefined4 Os_Thread_SetPriority(uint param_1,uint param_2);
#define iRam0200dd8c (*(int *)(uintptr_t)0x200dd8cu)
#define uRam0200dd90 (*(uint *)(uintptr_t)0x200dd90u)
