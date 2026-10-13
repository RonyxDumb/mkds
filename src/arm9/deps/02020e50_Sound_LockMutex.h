#pragma once
/* Function-specific inferred declarations. */
void Os_Mutex_Lock(int param_1);
void Sound_LockMutex(void);
#define pcRam02020e5c (*(__typeof__(Os_Mutex_Lock) **)(uintptr_t)0x2020e5cu)
#define uRam02020e60 (*(undefined4 *)(uintptr_t)0x2020e60u)
