#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
bool Card_Request(uint param_1,int param_2,int param_3);
bool Fifo_IsHandlerReady(uint param_1,int param_2);
undefined4 Fifo_SendWord(uint param_1,int param_2,uint param_3);
undefined4 Mem_DcDrainWriteBuffer(void);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_SpinWait(uint param_1);
void Os_Thread_Sleep(int param_1);

