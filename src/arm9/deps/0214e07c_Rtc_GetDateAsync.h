#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
undefined4 Rtc_GetDateAsync(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void Rtc_ReadRawDateAsync(void);
#define puRam0214e0f0 (*(undefined4 **)(uintptr_t)0x214e0f0u)
