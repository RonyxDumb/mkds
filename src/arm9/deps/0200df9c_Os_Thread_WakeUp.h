#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
void Os_RescheduleThread(void);
undefined4 Os_RestoreIrq(void);
uint Os_ThreadQueue_Pop(uint *param_1);
void Os_Thread_WakeUp(uint *param_1);

