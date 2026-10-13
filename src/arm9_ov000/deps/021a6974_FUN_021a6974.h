#pragma once
/* Function-specific inferred declarations. */
undefined4 FUN_021a5b30(void);
uint FUN_021a6974(undefined4 param_1,undefined4 param_2,uint param_3);
#define DAT_021a6a84 (*(undefined4 *)(uintptr_t)0x21a6a84u)
#define DAT_021a6a88 (*(int *)(uintptr_t)0x21a6a88u)
#define DAT_021a6a8c (*(int *)(uintptr_t)0x21a6a8cu)
#define DAT_021a6a90 (*(int *)(uintptr_t)0x21a6a90u)
#define DAT_021a6a94 (*(undefined4 *)(uintptr_t)0x21a6a94u)
#define DAT_021a6a98 (*(undefined4 *)(uintptr_t)0x21a6a98u)
#define DAT_021a6a9c (*(int *)(uintptr_t)0x21a6a9cu)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
void Os_Mutex_Lock(int param_1);
#define func_0x0200ed34 Os_Mutex_Lock
void Os_Mutex_Unlock(int param_1);
#define func_0x0200ecc4 Os_Mutex_Unlock
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
#define func_0x0214d1fc Mem_CpuCopy8
int func_02144438(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4);
#define func_0x02144438 func_02144438
void Os_Thread_Sleep(int param_1);
#define func_0x0200e01c Os_Thread_Sleep
