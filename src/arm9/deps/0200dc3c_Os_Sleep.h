#pragma once
/* Function-specific inferred declarations. */
void Os_Alarm_Create(undefined4 *param_1);
void Os_Alarm_Set(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Sleep(int param_1);
void Os_Thread_Sleep(int param_1);
#define iRam0200dcd0 (*(int *)(uintptr_t)0x200dcd0u)
#define uRam0200dccc (*(uint *)(uintptr_t)0x200dcccu)
#define uRam0200dcd4 (*(undefined4 *)(uintptr_t)0x200dcd4u)
