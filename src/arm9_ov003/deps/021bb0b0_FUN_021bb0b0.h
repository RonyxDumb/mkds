#pragma once
/* Function-specific inferred declarations. */
void FUN_021bb03c(void);
undefined4 FUN_021bb0b0(void);
undefined4 FUN_021be3b8(void);
#define DAT_021bb148 (*(int **)(uintptr_t)0x21bb148u)
#define DAT_021bb14c (*(int **)(uintptr_t)0x21bb14cu)
#define DAT_021bb150 (*(undefined4 **)(uintptr_t)0x21bb150u)
#define DAT_021bb154 (*(undefined4 *)(uintptr_t)0x21bb154u)
#define DAT_021bb158 (*(undefined4 *)(uintptr_t)0x21bb158u)
#define DAT_021bb15c (*(int **)(uintptr_t)0x21bb15cu)
#define DAT_021bb160 (*(undefined4 **)(uintptr_t)0x21bb160u)
#define DAT_021bb164 (*(int **)(uintptr_t)0x21bb164u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
void Os_Sleep(int param_1);
#define func_0x0200dc3c Os_Sleep
bool Os_Thread_IsTerminated(int param_1);
#define func_0x0200e070 Os_Thread_IsTerminated
void Os_Thread_WakeUpDirect(int param_1);
#define func_0x0200df68 Os_Thread_WakeUpDirect
void Os_Thread_Join(int param_1);
#define func_0x0200e084 Os_Thread_Join
