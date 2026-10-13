#pragma once
/* Function-specific inferred declarations. */
void Arm_Context_Create(undefined4 *param_1,int param_2,int param_3);
void MIi_CpuClear32(undefined4 param_1,undefined4 *param_2,int param_3);
void Os_AllocateThreadId(void);
longlong Os_DisableIrq(void);
void Os_InsertThread(int param_1);
undefined4 Os_RestoreIrq(void);
void Os_Thread_Create(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6);
void Os_Thread_SetDestructor(int param_1,undefined4 param_2);
#define uRam0200e37c (*(undefined4 *)(uintptr_t)0x200e37cu)
#define uRam0200e380 (*(undefined4 *)(uintptr_t)0x200e380u)
#define uRam0200e384 (*(undefined4 *)(uintptr_t)0x200e384u)
