#pragma once
/* Function-specific inferred declarations. */
undefined4 Os_Lock_UnlockImpl(uint param_1,undefined4 *param_2,code *param_3,int param_4);
void Os_Lock_Unlock(void);
#define pcRam0200cf2c (*(__typeof__(Os_Lock_UnlockImpl) **)(uintptr_t)0x200cf2cu)
