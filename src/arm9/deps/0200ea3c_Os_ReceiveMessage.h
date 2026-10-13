#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
undefined4 Os_ReceiveMessage(int param_1,uint *param_2,uint param_3);
undefined4 Os_RestoreIrq(void);
void Os_Thread_Sleep(int param_1);
void Os_Thread_WakeUp(uint *param_1);
undefined8 _s32_div_f(uint param_1,uint param_2);

