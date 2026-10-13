#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_Exit(void);
uint Os_Thread_GetPriority(int param_1);
undefined4 Os_Thread_SetPriority(uint param_1,uint param_2);
void Os_Thread_Sleep(int param_1);
void func_0200b08c(int param_1);

