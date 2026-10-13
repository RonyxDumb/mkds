#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
void Card_InitializeContext(void);
void Card_SetEnabled(undefined4 param_1);
void Fifo_RegisterHandler(uint param_1,int param_2);
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
void Mem_CpuFastMemorySet(undefined4 param_1,undefined4 *param_2,uint param_3);
void Os_Thread_Create(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6);
void Os_Thread_WakeUpDirect(int param_1);
#define psRam021459b4 (*(short **)(uintptr_t)0x21459b4u)
#define puRam021459ac (*(undefined4 **)(uintptr_t)0x21459acu)
#define uRam021459b0 (*(undefined4 *)(uintptr_t)0x21459b0u)
#define uRam021459b8 (*(undefined4 *)(uintptr_t)0x21459b8u)
#define uRam021459bc (*(undefined4 *)(uintptr_t)0x21459bcu)
#define uRam021459c0 (*(undefined4 *)(uintptr_t)0x21459c0u)
#define uRam021459c4 (*(undefined4 *)(uintptr_t)0x21459c4u)
#define uRam021459c8 (*(undefined4 *)(uintptr_t)0x21459c8u)
