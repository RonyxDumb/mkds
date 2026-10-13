#pragma once
/* Function-specific inferred declarations. */
void Os_AlarmHandlerImpl(void);
void Os_DisableIrqHandler(uint param_1);
undefined8 Os_GetTick(void);
void Os_InsertAlarm(int param_1,undefined4 param_2,undefined4 param_3);
void Os_SetAlarmTimer(int param_1);
#define iRam0200f8b0 (*(int *)(uintptr_t)0x200f8b0u)
#define puRam0200f8ac (*(undefined2 **)(uintptr_t)0x200f8acu)
#define puRam0200f8b4 (*(uint **)(uintptr_t)0x200f8b4u)
