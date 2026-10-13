#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Terminate(void);
void func_02009c04(void);
undefined4 func_02009c34(void);
#define iRam02009c30 (*(int *)(uintptr_t)0x2009c30u)
#define piRam02009c2c (*(int **)(uintptr_t)0x2009c2cu)
