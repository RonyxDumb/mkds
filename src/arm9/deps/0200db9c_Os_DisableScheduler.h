#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
uint Os_DisableScheduler(void);
undefined4 Os_RestoreIrq(void);
#define piRam0200dbd0 (*(int **)(uintptr_t)0x200dbd0u)
