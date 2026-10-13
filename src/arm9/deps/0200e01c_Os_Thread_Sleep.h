#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
void Os_RescheduleThread(void);
undefined4 Os_RestoreIrq(void);
void Os_ThreadQueue_Queue(uint *param_1,uint param_2);
void Os_Thread_Sleep(int param_1);
#define uRam0200e06c (*(uint *)(uintptr_t)0x200e06cu)
