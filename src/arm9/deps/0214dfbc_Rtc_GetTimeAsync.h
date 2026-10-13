#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
undefined4 Rtc_GetTimeAsync(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void Rtc_ReadRawTimeAsync(void);
#define puRam0214e034 (*(undefined4 **)(uintptr_t)0x214e034u)
