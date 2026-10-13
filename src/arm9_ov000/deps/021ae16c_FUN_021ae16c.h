#pragma once
/* Function-specific inferred declarations. */
undefined4 FUN_021ae16c(int param_1);
undefined4 FUN_021ae314(void);
void FUN_021aefc0(int param_1,undefined4 param_2,undefined4 param_3);
#define DAT_021ae1e0 (*(int **)(uintptr_t)0x21ae1e0u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
undefined8 Os_GetTick(void);
#define func_0x0200f5ac Os_GetTick
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
void Os_Thread_Sleep(int param_1);
#define func_0x0200e01c Os_Thread_Sleep
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
