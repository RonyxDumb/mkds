#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
uint Os_SetThreadSwitchCallback(undefined4 param_1);
#define iRam0200dc18 (*(int *)(uintptr_t)0x200dc18u)
