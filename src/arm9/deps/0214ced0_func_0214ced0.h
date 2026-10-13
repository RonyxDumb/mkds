#pragma once
/* Function-specific inferred declarations. */
void MI_WaitDma(int param_1);
void MIi_CheckDma0SourceAddress(int param_1,uint param_2,int param_3,int param_4);
longlong Os_DisableIrq(void);
uint Os_EnableIrqHandler(uint param_1);
uint Os_GetIrqHandler(uint param_1);
undefined4 Os_RestoreIrq(void);
void Os_SetIrqHandler(uint param_1,undefined4 param_2);
void func_0214ce08(void);
void func_0214ced0(undefined4 param_1,undefined4 param_2,int param_3,code *param_4,undefined4 param_5);
#define puRam0214cfd8 (*(undefined4 **)(uintptr_t)0x214cfd8u)
#define puRam0214cfdc (*(uint **)(uintptr_t)0x214cfdcu)
#define uRam0214cfe0 (*(undefined4 *)(uintptr_t)0x214cfe0u)
