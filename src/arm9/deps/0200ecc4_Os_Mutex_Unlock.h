#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
void Os_Mutex_DequeueThread(int param_1,int param_2);
void Os_Mutex_Unlock(int param_1);
undefined4 Os_RestoreIrq(void);
void Os_Thread_WakeUp(uint *param_1);
#define iRam0200ed30 (*(int *)(uintptr_t)0x200ed30u)
