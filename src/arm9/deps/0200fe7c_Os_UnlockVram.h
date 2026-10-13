#pragma once
/* Function-specific inferred declarations. */
int Os_CountLeadingZeroBits(undefined4 param_1);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_UnlockVram(uint param_1,uint param_2);
#define iRam0200ff00 (*(int *)(uintptr_t)0x200ff00u)
#define puRam0200fef8 (*(uint **)(uintptr_t)0x200fef8u)
#define uRam0200fefc (*(uint *)(uintptr_t)0x200fefcu)
