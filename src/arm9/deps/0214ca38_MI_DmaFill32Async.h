#pragma once
/* Function-specific inferred declarations. */
void MI_DmaFill32Async(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,code *param_5,undefined4 param_6);
void MI_WaitDma(int param_1);
void OSi_EnterDmaCallback(int param_1,undefined4 param_2,undefined4 param_3);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void func_01fffe8c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
#define iRam0214cb0c (*(int *)(uintptr_t)0x214cb0cu)
