#pragma once
/* Function-specific inferred declarations. */
bool Fifo_IsHandlerReady(uint param_1,int param_2);
void Fifo_RegisterHandler(uint param_1,int param_2);
void Os_SpinWait(uint param_1);
bool Sound_IsCommandAvailable(void);
void Sound_RegisterFifoHandler(void);
#define uRam02020fec (*(undefined4 *)(uintptr_t)0x2020fecu)
