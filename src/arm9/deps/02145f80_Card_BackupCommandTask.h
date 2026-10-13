#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
void Card_BackupCommandTask(uint param_1);
bool Card_Request(uint param_1,int param_2,int param_3);
void DC_InvalidateRangeNoClean(uint param_1,int param_2);
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
undefined4 Mem_DcDrainWriteBuffer(void);
longlong Os_DisableIrq(void);
void Os_ReferSymbol(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_WakeUp(uint *param_1);
void Os_Thread_WakeUpDirect(int param_1);
#define uRam02146138 (*(undefined4 *)(uintptr_t)0x2146138u)
