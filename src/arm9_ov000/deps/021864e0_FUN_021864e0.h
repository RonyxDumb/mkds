#pragma once
/* Function-specific inferred declarations. */
void FUN_021864e0(void);
#define DAT_02186540 (*(int **)(uintptr_t)0x2186540u)
#define DAT_02186544 (*(int *)(uintptr_t)0x2186544u)
#define DAT_02186548 (*(int *)(uintptr_t)0x2186548u)
#define DAT_0218654c (*(int *)(uintptr_t)0x218654cu)
#define DAT_02186550 (*(int *)(uintptr_t)0x2186550u)
#define DAT_02186554 (*(undefined4 *)(uintptr_t)0x2186554u)
#define DAT_02186558 (*(undefined4 *)(uintptr_t)0x2186558u)
#define DAT_0218655c (*(int *)(uintptr_t)0x218655cu)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
void Os_Mutex_Initialize(unsigned int p0);
#define func_0x0200edc0 Os_Mutex_Initialize
bool Os_Thread_IsTerminated(int param_1);
#define func_0x0200e070 Os_Thread_IsTerminated
void Os_Thread_Create(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5, undefined4 param_6);
#define func_0x0200e28c Os_Thread_Create
void Os_Thread_WakeUpDirect(int param_1);
#define func_0x0200df68 Os_Thread_WakeUpDirect
