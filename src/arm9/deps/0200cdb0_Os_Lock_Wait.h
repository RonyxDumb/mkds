#pragma once
/* Function-specific inferred declarations. */
void Os_SpinWait(uint param_1);
void Os_Lock_Wait(void);
#define pcRam0200cdbc (*(__typeof__(Os_SpinWait) **)(uintptr_t)0x200cdbcu)
