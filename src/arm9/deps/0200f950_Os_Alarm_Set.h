#pragma once
/* Function-specific inferred declarations. */
void Os_Alarm_Set(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
longlong Os_DisableIrq(void);
undefined8 Os_GetTick(void);
void Os_InsertAlarm(int param_1,undefined4 param_2,undefined4 param_3);
undefined4 Os_RestoreIrq(void);
void Os_Terminate(void);

