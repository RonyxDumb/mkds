#pragma once
/* Function-specific inferred declarations. */
bool Rtc_SendFifoWord(uint param_1);
void Rtc_WriteRawStatus2Async(void);
#define pcRam0214e1bc (*(__typeof__(Rtc_SendFifoWord) **)(uintptr_t)0x214e1bcu)
