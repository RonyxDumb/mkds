#pragma once
/* Function-specific inferred declarations. */
int FUN_021b02bc(void);
#define DAT_021b02f4 (*(undefined4 *)(uintptr_t)0x21b02f4u)
#define DAT_021b02f8 (*(int **)(uintptr_t)0x21b02f8u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
bool Os_Thread_IsTerminated(int param_1);
#define func_0x0200e070 Os_Thread_IsTerminated
void Os_Thread_WakeUpDirect(int param_1);
#define func_0x0200df68 Os_Thread_WakeUpDirect
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
