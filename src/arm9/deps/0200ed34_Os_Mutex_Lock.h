#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
void Os_Mutex_EnqueueThread(int param_1,int param_2);
void Os_Mutex_Lock(int param_1);
undefined4 Os_RestoreIrq(void);
void Os_Thread_Sleep(int param_1);
#define iRam0200edbc (*(int *)(uintptr_t)0x200edbcu)
