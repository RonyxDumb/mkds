#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_Sleep(int param_1);
void WaitForIRQ(int param_1,uint param_2);
#define iRam0200c908 (*(int *)(uintptr_t)0x200c908u)
#define iRam0200c90c (*(int *)(uintptr_t)0x200c90cu)
#define uRam0200c910 (*(undefined4 *)(uintptr_t)0x200c910u)
