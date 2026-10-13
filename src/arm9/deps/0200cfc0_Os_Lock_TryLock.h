#pragma once
/* Function-specific inferred declarations. */
void Os_Lock_TryLockImpl(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4 );
void Os_Lock_TryLock(void);
#define pcRam0200cfcc (*(__typeof__(Os_Lock_TryLockImpl) **)(uintptr_t)0x200cfccu)
