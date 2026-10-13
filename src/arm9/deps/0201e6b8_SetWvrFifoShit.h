#pragma once
/* Function-specific inferred declarations. */
bool Fifo_IsHandlerReady(uint param_1,int param_2);
void Fifo_RegisterHandler(uint param_1,int param_2);
undefined4 Fifo_SendWord(uint param_1,int param_2,uint param_3);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
undefined4 SetWvrFifoShit(int param_1,undefined4 param_2);
void func_0214d5b8(void);
#define iRam0201e7a0 (*(int *)(uintptr_t)0x201e7a0u)
#define piRam0201e798 (*(int **)(uintptr_t)0x201e798u)
#define puRam0201e7a4 (*(undefined4 **)(uintptr_t)0x201e7a4u)
#define uRam0201e79c (*(undefined4 *)(uintptr_t)0x201e79cu)
