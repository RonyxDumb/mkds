#pragma once
/* Function-specific inferred declarations. */
void Os_Alarm_Cancel(undefined4 *param_1);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_SetAlarmTimer(int param_1);
#define puRam0200f94c (*(uint **)(uintptr_t)0x200f94cu)
