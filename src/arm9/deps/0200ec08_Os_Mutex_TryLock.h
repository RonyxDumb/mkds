#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
void Os_Mutex_EnqueueThread(int param_1,int param_2);
undefined4 Os_Mutex_TryLock(int param_1);
undefined4 Os_RestoreIrq(void);
#define iRam0200ec78 (*(int *)(uintptr_t)0x200ec78u)
