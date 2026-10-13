#pragma once
/* Function-specific inferred declarations. */
bool Rtc_SendFifoWord(uint param_1);
void Rtc_ReadRawDateAsync(void);
#define pcRam0214e1dc (*(__typeof__(Rtc_SendFifoWord) **)(uintptr_t)0x214e1dcu)
