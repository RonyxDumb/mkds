#pragma once
/* Function-specific inferred declarations. */
void Card_UnlockResource(uint param_1,uint param_2);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Terminate(void);
void Os_Thread_WakeUp(uint *param_1);
#define uRam02145a6c (*(uint *)(uintptr_t)0x2145a6cu)
