#pragma once
/* Function-specific inferred declarations. */
uint FUN_021a797c(int param_1,undefined4 param_2,uint param_3,undefined2 *param_4,int *param_5,int param_6);
undefined4 FUN_021a8a80(int param_1);
#define DAT_021a7a58 (*(int *)(uintptr_t)0x21a7a58u)
#define DAT_021a7a5c (*(int *)(uintptr_t)0x21a7a5cu)
#define DAT_021a7a60 (*(int *)(uintptr_t)0x21a7a60u)
#define DAT_021a7a64 (*(int **)(uintptr_t)0x21a7a64u)
#define DAT_021a7a68 (*(int *)(uintptr_t)0x21a7a68u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
#define func_0x0214d1fc Mem_CpuCopy8
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
void Os_Thread_Sleep(int param_1);
#define func_0x0200e01c Os_Thread_Sleep
