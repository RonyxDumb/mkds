#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_Sleep(int param_1);
bool WaitForPendingCardOperation(void);
#define uRam02145874 (*(uint *)(uintptr_t)0x2145874u)
