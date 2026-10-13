#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
uint Os_EnableScheduler(void);
undefined4 Os_RestoreIrq(void);
#define piRam0200db98 (*(int **)(uintptr_t)0x200db98u)
