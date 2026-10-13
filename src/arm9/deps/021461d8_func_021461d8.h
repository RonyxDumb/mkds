#pragma once
/* Function-specific inferred declarations. */
void Card_SetTask(undefined4 param_1);
void EnsureCardEnabled(void);
void Mem_DmaStop(int param_1);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_Sleep(int param_1);
int StructSZ_SomeFn(int param_1);
void func_02146148(void);
void func_021461d8(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7);
void task_fn(void);
#define iRam021462ec (*(int *)(uintptr_t)0x21462ecu)
#define iRam021462fc (*(int *)(uintptr_t)0x21462fcu)
#define uRam021462f0 (*(undefined4 *)(uintptr_t)0x21462f0u)
#define uRam021462f4 (*(uint *)(uintptr_t)0x21462f4u)
#define uRam021462f8 (*(undefined4 *)(uintptr_t)0x21462f8u)
