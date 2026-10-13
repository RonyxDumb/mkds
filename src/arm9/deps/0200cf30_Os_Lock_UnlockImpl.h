#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
longlong Os_DisableIrqFiq(void);
undefined4 Os_Lock_UnlockImpl(uint param_1,undefined4 *param_2,code *param_3,int param_4);
undefined4 Os_RestoreIrq(void);
undefined4 Os_RestoreIrqFiq(void);

