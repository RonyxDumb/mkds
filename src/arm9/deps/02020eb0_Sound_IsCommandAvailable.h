#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
undefined4 Os_IsEmulator(void);
undefined4 Os_RestoreIrq(void);
bool Sound_IsCommandAvailable(void);
#define puRam02020ef4 (*(undefined4 **)(uintptr_t)0x2020ef4u)
