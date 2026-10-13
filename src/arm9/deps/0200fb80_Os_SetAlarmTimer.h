#pragma once
/* Function-specific inferred declarations. */
uint Os_EnableIrqHandler(uint param_1);
undefined8 Os_GetTick(void);
void Os_SetAlarmTimer(int param_1);
void Os_SetTimerIrqHandler(int param_1,undefined4 param_2,undefined4 param_3);
#define puRam0200fc0c (*(undefined2 **)(uintptr_t)0x200fc0cu)
#define puRam0200fc18 (*(undefined2 **)(uintptr_t)0x200fc18u)
#define uRam0200fc10 (*(undefined4 *)(uintptr_t)0x200fc10u)
#define uRam0200fc14 (*(uint *)(uintptr_t)0x200fc14u)
