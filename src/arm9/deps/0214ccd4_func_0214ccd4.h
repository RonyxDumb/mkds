#pragma once
/* Function-specific inferred declarations. */
void MI_WaitDma(int param_1);
void MIi_CheckAnotherAutoDMA(int param_1,uint param_2);
void MIi_CheckDma0SourceAddress(int param_1,uint param_2,int param_3,int param_4);
void OSi_EnterDmaCallback(int param_1,undefined4 param_2,undefined4 param_3);
void func_01ffff38(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void func_0214ccd4(undefined4 param_1,undefined4 param_2,uint param_3,code *param_4,undefined4 param_5);
#define puRam0214cd88 (*(undefined4 **)(uintptr_t)0x214cd88u)
#define uRam0214cd8c (*(undefined4 *)(uintptr_t)0x214cd8cu)
#define uRam0214cd90 (*(undefined4 *)(uintptr_t)0x214cd90u)
