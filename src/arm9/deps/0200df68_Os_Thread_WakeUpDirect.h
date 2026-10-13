#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
void Os_RescheduleThread(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_WakeUpDirect(int param_1);

