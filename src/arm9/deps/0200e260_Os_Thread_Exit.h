#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
void Os_Thread_Exit(void);
void Os_Thread_ExitImpl(uint *param_1,uint param_2);
#define iRam0200e288 (*(int *)(uintptr_t)0x200e288u)
