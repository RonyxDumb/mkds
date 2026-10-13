#pragma once
/* Function-specific inferred declarations. */
void DC_InvalidateRangeNoClean(uint param_1,int param_2);
void DC_SomeClean(uint param_1,int param_2);
undefined4 Fifo_SendWord(uint param_1,int param_2,uint param_3);
void MI_DmaCopy32(int param_1,undefined4 param_2,undefined4 param_3,uint param_4);
undefined4 OS_JamMessage(int param_1,undefined4 param_2,uint param_3);
undefined4 Os_MessageQueue_Send(int param_1,undefined4 param_2,uint param_3);
undefined4 Os_ReceiveMessage(int param_1,uint *param_2,uint param_3);
undefined4 WM_SomeFn(ushort param_1,uint param_2,undefined4 param_3,undefined4 param_4);
#define uRam02142c04 (*(undefined4 *)(uintptr_t)0x2142c04u)
#define uRam02142c08 (*(uint *)(uintptr_t)0x2142c08u)
