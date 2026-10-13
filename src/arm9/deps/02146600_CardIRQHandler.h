#pragma once
/* Function-specific inferred declarations. */
void CardIRQHandler(void);
void MaybeGamecardTransferSY(void);
void Mem_DmaStop(int param_1);
longlong Os_DisableIrq(void);
void Os_DisableIrqHandler(uint param_1);
undefined4 Os_RestoreIrq(void);
void Os_Thread_WakeUp(uint *param_1);
void Os_Thread_WakeUpDirect(int param_1);
uint SetIF(undefined4 param_1);
#define uRam021466d4 (*(uint *)(uintptr_t)0x21466d4u)
