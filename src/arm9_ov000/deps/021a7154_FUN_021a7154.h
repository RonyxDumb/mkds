#pragma once
/* Function-specific inferred declarations. */
int FUN_021a7154(int param_1,int param_2,undefined2 *param_3);
int FUN_021a72a4(undefined2 *param_1);
#define DAT_021a71a0 (*(undefined4 *)(uintptr_t)0x21a71a0u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
void Os_MessageQueue_Initialize(uint *param_1,uint param_2,uint param_3);
#define func_0x0200eb90 Os_MessageQueue_Initialize
void Os_Mutex_Initialize(unsigned int p0);
#define func_0x0200edc0 Os_Mutex_Initialize
void Os_Thread_Create(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5, undefined4 param_6);
#define func_0x0200e28c Os_Thread_Create
void Os_Thread_WakeUpDirect(int param_1);
#define func_0x0200df68 Os_Thread_WakeUpDirect
