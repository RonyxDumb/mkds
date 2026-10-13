#pragma once
/* Function-specific inferred declarations. */
void Os_Mutex_Unlock(int param_1);
void Sound_UnlockMutex(void);
#define pcRam02020e48 (*(__typeof__(Os_Mutex_Unlock) **)(uintptr_t)0x2020e48u)
#define uRam02020e4c (*(undefined4 *)(uintptr_t)0x2020e4cu)
