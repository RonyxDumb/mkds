#pragma once
/* Function-specific inferred declarations. */
int FUN_021a8118(int param_1);
int FUN_021a813c(int param_1,int param_2,int param_3,uint *param_4,int param_5);
#define DAT_021a81a0 (*(int *)(uintptr_t)0x21a81a0u)
#define DAT_021a81a4 (*(int *)(uintptr_t)0x21a81a4u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
void Os_Thread_Sleep(int param_1);
#define func_0x0200e01c Os_Thread_Sleep
