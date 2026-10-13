#pragma once
/* Function-specific inferred declarations. */
void DC_InvalidateRangeNoClean(uint param_1,int param_2);
void DC_SomeClean(uint param_1,int param_2);
bool Fifo_IsHandlerReady(uint param_1,int param_2);
void Fifo_RegisterHandler(uint param_1,int param_2);
void Mem_DmaFill32(int param_1,undefined4 param_2,undefined4 param_3,uint param_4);
void Os_MessageQueue_Initialize(uint *param_1,uint param_2,uint param_3);
undefined4 Os_MessageQueue_Send(int param_1,undefined4 param_2,uint param_3);
void Wm_DisableCallbackControl(void);
undefined4 Wm_InitializeImpl(int *param_1,uint param_2,undefined4 param_3);
int func_0214358c(int param_1,undefined4 param_2,undefined4 param_3);
void func_0214d5b8(void);
#define puRam02142e60 (*(ushort **)(uintptr_t)0x2142e60u)
#define puRam02142e64 (*(uint **)(uintptr_t)0x2142e64u)
#define puRam02142e70 (*(undefined2 **)(uintptr_t)0x2142e70u)
#define uRam02142e68 (*(undefined4 *)(uintptr_t)0x2142e68u)
#define uRam02142e6c (*(undefined4 *)(uintptr_t)0x2142e6cu)
#define uRam02142e74 (*(undefined4 *)(uintptr_t)0x2142e74u)
